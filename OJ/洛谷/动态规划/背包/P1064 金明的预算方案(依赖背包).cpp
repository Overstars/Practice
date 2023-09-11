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
struct node
{
	bool vis;
	int v[3],w[3];
} a[105];
int dp[maxn],w[maxn];
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m;//容量v和m个物品
	cin>>n>>m;
	for(int i=1,v,w,p;i<=m;i++)
	{
		cin>>v>>w>>p;
		if(p==0)
		{
			a[i].vis=1;
			a[i].v[0]=v;
			a[i].w[0]=w*v;
		}
		else{
			if(a[p].v[1]>0)
			{
				a[p].v[2]=v;
				a[p].w[2]=w*v;
			}
			else{
				a[p].v[1]=v;
				a[p].w[1]=w*v;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(!a[i].vis)
			continue;
		int v[4]={a[i].v[0],a[i].v[0]+a[i].v[1],a[i].v[0]+a[i].v[2],a[i].v[0]+a[i].v[1]+a[i].v[2]};
		int w[4]={a[i].w[0],a[i].w[0]+a[i].w[1],a[i].w[0]+a[i].w[2],a[i].w[0]+a[i].w[1]+a[i].w[2]};
		for(int j=n;j>=v[0];j--)
		{
			dp[j]=max(dp[j],dp[j-v[0]]+w[0]);
			if(j>=v[1])
				dp[j]=max(dp[j],dp[j-v[1]]+w[1]);
			if(j>=v[2])
				dp[j]=max(dp[j],dp[j-v[2]]+w[2]);
			if(j>=v[3])
				dp[j]=max(dp[j],dp[j-v[3]]+w[3]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}

