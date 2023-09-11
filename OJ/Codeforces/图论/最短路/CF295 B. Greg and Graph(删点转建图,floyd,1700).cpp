//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=505,inf=0x3f3f3f3f,mod=1000000007;
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
bool vis[maxn];
ll del[maxn],dis[maxn][maxn],ans[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>dis[i][j];
	for(int i=1;i<=n;i++)//删点的顺序
		cin>>del[i];
	for(int k=n;k>=1;k--)
	{
		int now=del[k];//加进来,做为中转点更新
		vis[now]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][now]+dis[now][j]);
				if(vis[i]&&vis[j])
				{
					ans[k]+=dis[i][j];
				}
			}
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}


