//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1e5+10,inf=0x3f3f3f3f,mod=1000000007;
ll ans=0;
struct node
{
    int a,b,c,d;
    node(){}
    node(int a,int b,int c,int d):
        a(a),b(b),c(c),d(d){}
};
vector<node>v[maxn];
void dfs(int l,int r,int a,int b,int c,int d)
{
    if(l>r)
    {
        ans=max(ans,1ll*(100+a)*(100+b)*(100+c)*(100+d));
        return ;
    }
    if(l==r)
    {
        if(v[l].size()==0)
        {
            dfs(l+1,r,a,b,c,d);
            return;
        }
        for(int i=0;i<v[l].size();++i)
            dfs(l+1,r,a+v[l][i].a,b+v[l][i].b,c+v[l][i].c,d+v[l][i].d);
        return;
    }
    if(v[l].size()==0)
    {
        dfs(l+1,r,a,b,c,d);
        return;
    }
    if(v[r].size()==0)
    {
        dfs(l,r-1,a,b,c,d);
        return;
    }
    for(int i=0;i<v[l].size();++i)
    {
        for(int j=0;j<v[r].size();++j)
        {
            dfs(l+1,r-1,a+v[l][i].a+v[r][j].a, b+v[l][i].b+v[r][j].b, c+v[l][i].c+v[r][j].c, d+v[l][i].d+v[r][j].d );
        }
    }
}
signed main()
{
    int T,n,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        ans=0;
        for(int i=1;i<=k;++i)
            v[i].clear();
        for(int i=0,t,a,b,c,d;i<n;++i)
        {
            scanf("%d%d%d%d%d",&t,&a,&b,&c,&d);
            v[t].push_back({a,b,c,d});
        }
        dfs(1,k,0,0,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
