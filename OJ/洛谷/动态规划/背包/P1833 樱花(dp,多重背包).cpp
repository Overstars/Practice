//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int cost[maxn],value[maxn],p[maxn],dp[maxn];
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int a,b,c,d,n,V;
	scanf("%d:%d %d:%d %d",&a,&b,&c,&d,&n);
	V=c*60+d-a*60-b;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&cost[i],&value[i],&p[i]);
	for(int i=1;i<=n;i++)
	{
		if(p[i]==1)
			for(int j=V;j>=cost[i];j--)
				dp[j]=max(dp[j],dp[j-cost[i]]+value[i]);
		else if(p[i]==0)//完全背包
			for(int j=cost[i];j<=V;j++)
				dp[j]=max(dp[j],dp[j-cost[i]]+value[i]);
		else{//多重背包,log(k)
			for(int j=1;j<=p[i];j<<=1)
			{//体积j*cost[i]的01背包
				for(int v=V;v>=j*cost[i];v--)
					dp[v]=max(dp[v],dp[v-cost[i]*j]+value[i]*j);
				p[i]-=j;
			}
			if(p[i])
				for(int v=V;v>=p[i]*cost[i];v--)
					dp[v]=max(dp[v],dp[v-cost[i]*p[i]]+value[i]*p[i]);
		}
	}
	printf("%d\n",dp[V]);
	return 0;
}


