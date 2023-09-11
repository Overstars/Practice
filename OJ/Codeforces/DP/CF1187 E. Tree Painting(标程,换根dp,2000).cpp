#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN = 200010;

int n;
struct edge{
    int ne, to;
    edge(int N=0, int T=0):ne(N),to(T){}
}e[MAXN<<1];
int fir[MAXN], num = 0;
inline void join(int a, int b)
{
    e[++num] = edge(fir[a], b);
    fir[a] = num;
}

ll siz[MAXN], f[MAXN], g[MAXN], ans = 0;

void dfs1(int u, int fa)
{
    siz[u] = 1;
    for(int i=fir[u];i;i=e[i].ne)
    {
        int v = e[i].to;
        if(v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        f[u] += f[v];
    }
    f[u] += siz[u];
}
void dfs2(int u, int fa)
{
    for(int i=fir[u];i;i=e[i].ne)
    {
        int v = e[i].to;
        if(v == fa) continue;
        g[v] = n - siz[v] + g[u] - siz[v];
        dfs2(v, u);
    }
}

int main()
{
//  freopen("stars3.in","r",stdin);
//  freopen("stars.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        join(a, b);
        join(b, a);
    }
    dfs1(1, 0);
    g[1] = f[1];
    dfs2(1, 0);
    ll ans = 0;
    for(int i=1;i<=n;i++)
        ans = max(ans, g[i]);
    printf("%lld\n",ans);
    return 0;
}
