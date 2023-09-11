#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=505,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn][maxn],dp[maxn][1024],ans[maxn],n,m;//第i行为j的个数
bool flag=0;
void dfs(int row,int now)
{
	if(row==n+1&&now)
	{
		flag=1;
		cout<<"TAK"<<endl;
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<' ';
		cout<<endl;
	}
	if(row>n)
		return;
	if(flag)
		return;
	for(int i=1;i<=m;i++)
	{
		ans[row]=i;
		dfs(row+1,now^a[row][i]);
	}
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>n>>m;//n行每行选一个,使得异或值大于0
//	vector<int>vec[maxn][11][2];
	for(int i=1;i<=n;i++)
//	{//某一位有奇数个1
		for(int j=1;j<=m;j++)
//		{
			cin>>a[i][j];
//			for(int k=0;(1<<k)<=a[i][j];k++)
//			{
//				if(a[i][j]&(1<<k))
//					vec[i][k][1].push_back(j);
//				else
//					vec[i][k][0].push_back(j);
//			}
//		}
//	}
	dfs(1,0);
	if(!flag)
		cout<<"NIE"<<endl;
	return 0;
}


