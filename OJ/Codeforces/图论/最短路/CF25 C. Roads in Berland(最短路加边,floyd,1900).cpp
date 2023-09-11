//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=305,inf=0x3f3f3f3f,mod=1000000007;
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
int mp[maxn][maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,u,v,w;
	ll ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>mp[i][j];
			if(i>j)
				ans+=mp[i][j];
		}
	cin>>k;
	while(k--)
	{
		cin>>u>>v>>w;
		if(w<mp[u][v])
		{
			ans-=mp[u][v]-w;
			mp[u][v]=mp[v][u]=w;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
				{
					ll path=min(mp[i][u]+w+mp[v][j],mp[i][v]+w+mp[u][j]);
					if(mp[i][j]>path||mp[i][j]>path)
					{
						ans-=mp[i][j]-path;
						mp[i][j]=mp[j][i]=path;
					}
				}
		}
		cout<<ans<<' ';
	}
	return 0;
}


