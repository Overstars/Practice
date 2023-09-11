#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int maxn=1005;
int w[maxn][maxn];//二分图间的权值
int lx[maxn],ly[maxn];
int linker[maxn];//B图匹配到的A图节点
int slack[maxn];
bool visy[maxn];//记录每一轮B图匹配过
int pre[maxn];
void bfs(int k,int n)
{
    int x,y=0,yy=0,delta;
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=n;i++)
		slack[i]=INF;
    linker[y]=k;
    while(1)
	{
        x=linker[y];
        delta=INF;
        visy[y]=true;
        for(int i=1;i<=n;i++)
		{
            if(!visy[i])
            {
                if(slack[i]>lx[x]+ly[i]-w[x][i])
                {
                    slack[i]=lx[x]+ly[i]-w[x][i];
                    pre[i]=y;
                }
                if(slack[i]<delta)
					delta=slack[i],yy=i;
            }
        }
        for(int i=0;i<=n;i++)
        {
            if( visy[i] )
				lx[linker[i]]-=delta,ly[i]+=delta;
            else
				slack[i]-=delta;
        }
        y=yy;
        if(linker[y]==-1)
			break;
    }
    while(y)
		linker[y]=linker[pre[y]],y=pre[y];
}
int KM(int n)
{
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    memset(linker,-1,sizeof(linker));
    for(int i=1;i<=n;i++)
	{
        memset(visy,false,sizeof(visy));
        bfs(i,n);
    }
    int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(linker[i]!=-1)
			ans+=w[linker[i]][i];
	}
	return ans;
}
ll a[maxn],p[maxn],c[maxn],t[maxn];
signed main()
{
	ll n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&p[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&t[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ll ww=0;
			for(int k=1;k<=n;k++)
				if(c[i]+t[j]>a[k])
					ww+=p[k];//加上所有可以击败的对手的荣誉点
			w[i][j]=ww;
		}
	}
	printf("%lld\n",KM(n));
	return 0;
}
