//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=105,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn][maxn],dp[maxn][maxn],pre[maxn][maxn];
void show(int x,int pos)
{
	if(x<=1)
		return;
	show(x-1,pre[x][pos]);
	if(x>1)
		cout<<pre[x][pos]<<' ';
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int f,v;//f花,v花瓶
	cin>>f>>v;
	for(int i=1;i<=f;i++)
		for(int j=1;j<=v;j++)
			cin>>a[i][j];
	fill(dp[0],dp[0]+maxn*maxn,-inf);
	dp[0][0]=0;
	for(int i=1;i<=f;i++)
	{
		dp[i][i]=dp[i-1][i-1]+a[i][i];
		pre[i][i]=i-1;
		for(int j=i;j<=v;j++)
		{
			for(int k=i-1;k<j;k++)
			{//这一应该可以用单调队列优化
				if(dp[i-1][k]+a[i][j]>dp[i][j])
				{
					dp[i][j]=dp[i-1][k]+a[i][j];
					pre[i][j]=k;
				}
			}
		}
	}
	int ans=-inf,p=0;
	for(int i=f;i<=v;i++)
	{
		if(dp[f][i]>ans)
		{
			ans=dp[f][i];
			p=i;
		}
	}
	cout<<ans<<endl;
	show(f,p);
	cout<<p<<endl;
	return 0;
}


