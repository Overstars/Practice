//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=105,inf=0x3f3f3f3f,mod=1e9;
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
ll tim[maxn][maxn],Kir[maxn][maxn];
ll Kirchhoff(int n)
{//传入基尔霍夫矩阵及其阶数
	n--;//删去最后一行和最后一列
	ll ans=1;
	for(int i=1;i<=n;i++)//求解行列式
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
	return (ans+mod)%mod;
}
char s[maxn][maxn];
void add(int u,int v)
{
	Kir[u][v]--;
	Kir[v][u]--;
	Kir[u][u]++;
	Kir[v][v]++;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i]+1;
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='.')
				tim[i][j]=++cnt;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='.')
			{
				if(tim[i-1][j])//左面有房间
					add(tim[i-1][j],tim[i][j]);
				if(tim[i][j-1])//上面有房间
					add(tim[i][j-1],tim[i][j]);
			}
	cout<<Kirchhoff(cnt)<<endl;
	return 0;
}
/*
 *求生成树个数
 *因为有墙,墙不能作为点,要动态开点
*/
