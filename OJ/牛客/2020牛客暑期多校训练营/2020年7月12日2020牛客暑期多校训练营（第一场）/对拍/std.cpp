#include<bits/stdc++.h>
#define lowbit(x) x&-x
using namespace std;
typedef long long ll;
const int MAX = 2e5 + 10;
//建立虚树点数tot < 2n, 空间开两倍

int n, w[MAX];
ll ans;

//树状数组
int c[MAX];
void upd(int p, int k) { for (; p <= n; p += lowbit(p)) c[p] += k; }
int query(int p) { int res = 0; for (; p; p -= lowbit(p)) res += c[p]; return res; }

int mindiv[MAX];
void sieve(int siz) {//筛mindiv
    for (int i = 2; i <= siz; i++)
        if (!mindiv[i])
            for (int j = i; j <= siz; j += i)
                if (!mindiv[j])
                    mindiv[j] = i;
}

int lcadep[MAX], dep[MAX];
int st[MAX], top, tot;//stack, top, tot:虚树点数
vector<int> g[MAX];//虚树
void add_edge(int u, int v) { g[u].push_back(v), g[v].push_back(u); }

void buildVirtualTree() {
    tot = n; st[top = 1] = 1;
    for (int i = 2; i <= n; i++) {
        dep[i] = dep[i - 1] + 1; int j = i;
        for (; j != mindiv[j]; j /= mindiv[j]) dep[i]++;
        lcadep[i] = query(n) - query(j - 1);
        for (j = i; j != 1; j /= mindiv[j]) upd(mindiv[j], 1);
    }
    for(int i=2;i<=n;i++)
		printf("dep[%d]=%d,lcadep[%d]=%d\n",i,dep[i],i,lcadep[i]);

    //建树
    for (int i = 2; i <= n; i++) {
        while (top > 1 && dep[st[top - 1]] >= lcadep[i])
            add_edge(st[top - 1], st[top]), top--;
        if (dep[st[top]] != lcadep[i]) {
            dep[++tot] = lcadep[i];
            add_edge(tot, st[top]);
            st[top] = tot;
        }
        st[++top] = i;
    }
    while (top > 1) add_edge(st[top - 1], st[top]), top--;
}

void dfs(int u, int fa) {
    printf("fa[%d]=%d\n",u,fa);
    ans += w[u] * dep[u];//ans最开始是rt = 1时的答案
    for (auto &v: g[u])
        if (v != fa) {
            dfs(v, u);
            w[u] += w[v];
        }
}

void dfs2(int u, int fa) {//如果rt移动之后答案变小就一直移动下去，直到答案不在变小
    for (auto &v: g[u])
        if (v != fa) {
            //rt从u转移到v的代价
            //+(w[1] - w[v]) - w[v]
            if (w[1] - 2 * w[v] < 0) {
                ans += 1ll * (w[1] - 2 * w[v]) * (dep[v] - dep[u]);//一步的代价*距离
                dfs2(v, u);
            }
        }
}

void init() {
    ans = top = 0;
    for (int i = 1; i <= tot; i++) g[i].clear(), c[i] = w[i] = lcadep[i] = dep[i] = 0;
}

int main() {

    sieve(1e5);
    while (~scanf("%d", &n)) {
        init();
        for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
        buildVirtualTree();
//        for(int i=1;i<=n;i++)
//            printf("dep[%d]=%d\n",i,dep[i]);
        int rt = 1; dfs(rt, 0); dfs2(rt, 0);
        printf("%lld\n", ans);
    }

    return 0;
}
