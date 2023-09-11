#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define SZ(v) (int)v.size()
#define pii pair<ll,ll>
#define fi first
#define se second
#define ll long long
using namespace std;
const ll INF = 1e16;
const int maxn = 3010;
const int maxm = 100010;
struct MCMF {
	struct Edge {
		ll v, cap, cost, rev;
	};
	ll flow, cost, s, t, n;
	ll dist[maxn], H[maxn], pv[maxn], pe[maxn];
	std::vector<Edge> G[maxn];
	bool dijkstra() {
		std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
		std::fill(dist, dist + n + 1, INF);
		dist[s] = 0; q.push({ 0, s });
		while (!q.empty()) {
			pii x = q.top(); q.pop();
			ll& u = x.se;
			if (dist[u] < x.fi) continue;
			for (int i = 0; i < SZ(G[u]); ++i) {
				Edge& e = G[u][i];
				ll& v = e.v;
				pii y(dist[u] + e.cost + H[u] - H[v], v);
				if (e.cap > 0 && dist[v] > y.fi) {
					dist[v] = y.fi;
					pe[v] = i, pv[v] = u;
					q.push(y);
				}
			}
		}

		if (dist[t] == INF) return false;
		for (int i = 0; i <= n; ++i) H[i] += dist[i];

		ll f = INF;
		for (int v = t; v != s; v = pv[v]) f = std::min(f, G[pv[v]][pe[v]].cap);

		flow += f;
		cost += f * H[t];

		for (int v = t; v != s; v = pv[v]) {
			Edge& e = G[pv[v]][pe[v]];
			e.cap -= f;
			G[v][e.rev].cap += f;
		}

		return true;
	}
	void solve(int s, int t) {
		this->s = s, this->t = t;
		flow = cost = 0;
		std::fill(H, H + n + 1, 0);
		while (dijkstra());
	}
	void ctu() {
		while (dijkstra());
	}
	void init(int n) {
		this->n = n;
		for (int i = 0; i <= n; ++i) G[i].clear();
	}
	void addEdge(int u, int v, int cap, ll cost) {
		G[u].push_back({ v, cap, cost, SZ(G[v]) });
		G[v].push_back({ u, 0, -cost, SZ(G[u]) - 1 });
	}

} mcmf;
struct point {
	ll x, y, id;
	point() {}
	point(ll x_, ll y_, ll id_) : x(x_), y(y_), id(id_) {}
	bool operator < (const point& k) const {
		return y == k.y ? x < k.x : y < k.y;
	}
};
int n; ll m;
ll a[55], b[55], c[55];
vector<point> p;
int uni[maxn];
ll ans[55];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d %lld", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
		p.clear();
		int tot = n;
		tot += 2;
		for (int i = 0; i < n; ++i) {
			double dx = -0.5 * b[i] / a[i];
			int l = floor(dx), r = ceil(dx);
			if (l == r) ++r;
			if (l > m) l = m;
			if (r <= 0) r = 1;
			int cnt = tot;
			while (cnt > 0) {
				if (l > 0) {
					p.emplace_back(point(l, a[i] * l * l + b[i] * l + c[i], i));
					--l; --cnt;
				}
				if (r <= m) {
					p.emplace_back(point(r, a[i] * r * r + b[i] * r + c[i], i));
					++r; --cnt;
				}
				if (l <= 0 && r > m) break;
			}
		}
		sort(p.begin(), p.end());
		int s = 0, ed = 3000;
		mcmf.init(ed + 1);
		for (int i = 0; i < p.size(); i++) {
			uni[i] = p[i].x;
		}
		int cntt = p.size();
		sort(uni, uni + cntt);
		cntt = unique(uni, uni + cntt) - uni;
		for (int i = 0; i < p.size(); i++) {
			p[i].x = lower_bound(uni, uni + cntt, p[i].x) - uni;
		}
		for (int i = 1; i <= n; i++) {
			mcmf.addEdge(1, 1 + i, 1, 0);
		}
		for (int i = 0; i < p.size(); i++) {
			mcmf.addEdge(1 + p[i].id + 1, n + 2 + p[i].x, 1, p[i].y);
		}
		for (int i = 0; i < cntt; i++) {
			mcmf.addEdge(i + n + 2, 3000, 1, 0);
		}
		for (int i = 0; i < n; i++) {
			mcmf.addEdge(0, 1, 1, 0);
			if (i == 0) mcmf.solve(s, ed);
			else mcmf.ctu();

			if (i == n - 1) printf("%lld\n", mcmf.cost);
			else printf("%lld ", mcmf.cost);
		}
	}
	return 0;
}
