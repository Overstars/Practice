#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;

ll m, n, mod;
ll a[N];
ll sum[N * 3];
ll addTag[N * 3];
ll mulTag[N * 3];

inline ll lc(ll x) { return x << 1; }

inline ll rc(ll x) { return x << 1 | 1; }

void pushUp(ll p) {
	sum[p] = (sum[lc(p)] + sum[rc(p)]) % mod;
}

void build(ll p, ll l, ll r) {
	addTag[p] = 0;
	mulTag[p] = 1;
	if (l == r) {
		sum[p] = a[l] % p;
		return;
	}
	ll mid = (l + r) >> 1;
	build(lc(p), l, mid);
	build(rc(p), mid + 1, r);
	pushUp(p);
}

void moveTag(ll p, ll l, ll r, ll mt, ll at) {
	sum[p] = (sum[p] * mt %mod+ at * (r - l + 1)%mod) % mod;
	addTag[p] = (addTag[p] * mt%mod + at % mod) % mod;
	mulTag[p] = (mulTag[p] * mt) % mod;
}

void pushDown(ll p, ll l, ll r) {
	ll mid = (l + r) >> 1;
	moveTag(lc(p), l, mid, mulTag[p], addTag[p]);
	moveTag(rc(p), mid + 1, r, mulTag[p], addTag[p]);
	mulTag[p] = 1;
	addTag[p] = 0;
}

void addUpdate(ll p, ll l, ll r, ll ql, ll qr, ll k) {
	if (ql <= l && r <= qr) {
		sum[p] = (sum[p] %mod + k * (r - l + 1)%mod) % mod;
		addTag[p] = (addTag[p] + k) % mod;
		return;
	}
	pushDown(p, l, r);
	ll mid = (l + r) >> 1;
	if (ql <= mid) {
		addUpdate(lc(p), l, mid, ql, qr, k);
	}
	if (mid < qr) {
		addUpdate(rc(p), mid + 1, r, ql, qr, k);
	}
	pushUp(p);
}

void mulUpdate(ll p, ll l, ll r, ll ql, ll qr, ll k) {
	if (ql <= l && r <= qr) {
		sum[p] = (sum[p] * k) % mod;
		mulTag[p] = (mulTag[p] * k) % mod;
		addTag[p] = (addTag[p] * k) % mod;
		return;
	}
	pushDown(p, l, r);
	ll mid = (l + r) >> 1;
	if (ql <= mid) {
		mulUpdate(lc(p), l, mid, ql, qr, k);
	}
	if (mid < qr) {
		mulUpdate(rc(p), mid + 1, r, ql, qr, k);
	}
	pushUp(p);
}

ll query(ll p, ll l, ll r, ll ql, ll qr) {
	if (ql <= l && r <= qr) return sum[p] % mod;
	pushDown(p, l, r);
	ll mid = (l + r) >> 1;
	ll ans = 0;
	if (ql <= mid) {
		ans += query(lc(p), l, mid, ql, qr);
		ans%mod;
	}
	if (mid < qr) {
		ans += query(rc(p), mid + 1, r, ql, qr);
		ans%mod;
	}
	return ans % mod;
}

int main() {
	freopen("P3373.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> mod;

	for (int i = 1; i <= n; ++i) cin >> a[i];

	build(1, 1, n);

	for (int i = 1; i <= m; ++i) {
		ll t, x, y, z;
		cin >> t;
		if (t == 1) {
			cin >> x >> y >> z;
			mulUpdate(1, 1, n, x, y, z);
		}
		else if (t == 2) {
			cin >> x >> y >> z;
			addUpdate(1, 1, n, x, y, z);
		}
		else {
			cin >> x >> y;
			cout << query(1, 1, n, x, y) << '\n';
		}
	}

	return 0;
}
