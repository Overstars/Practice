//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=105,inf=0x3f3f3f3f,mod=998244353;
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
ll qmod(ll a,ll b,ll mod)  //快速幂
{
	ll ans=1;
	a=a%mod;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
ll Kir[maxn][maxn];
ll Kirchhoff(int n)
{//传入基尔霍夫矩阵及其阶数
	n--;//删去最后一行和最后一列
	ll ans=1;
	for(int i=1;i<=n;i++)//高斯消元求解行列式
	{
		for(int j=i+1;j<=n;j++)
			while(Kir[j][i])
			{
				ll tmp=Kir[i][i]/Kir[j][i];
				for(int k=i;k<=n;k++)
				{
					Kir[i][k]=(Kir[i][k]-tmp*Kir[j][k]%mod+mod)%mod;
					std::swap(Kir[j][k],Kir[i][k]);
				}
				ans=-ans;
			}
		ans=(ans*Kir[i][i])%mod;
	}
	return (ans+mod)%mod;//得到生成树个数
}
struct edge
{
	int u,v;
	ll w;
};
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		vector<edge>E;
		for(int i=1,u,v;i<=m;i++)
		{
			ll w;
			cin>>u>>v>>w;
			E.push_back({u,v,w});
			Kir[u][u]++;
			Kir[v][v]++;
			Kir[u][v]--;
			Kir[v][u]--;
		}
		ll ans=0,tot=Kirchhoff(n);
		for(int i=0;i<=31;i++)//拆位,按位分别算贡献
		{
			memset(Kir,0,sizeof(Kir));
			for(auto &e:E)
			{
				if(e.w&(1ll<<i))
				{
					Kir[e.u][e.u]++;
					Kir[e.v][e.v]++;
					Kir[e.u][e.v]--;
					Kir[e.v][e.u]--;
				}
			}
			ans=(ans+((1ll<<i)%mod)*Kirchhoff(n)%mod*qmod(tot,mod-2,mod)%mod)%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}


