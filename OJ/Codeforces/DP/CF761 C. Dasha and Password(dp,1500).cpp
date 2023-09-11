#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
const int maxn=105,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
char s[maxn][maxn];
int dp[maxn][7];//0数字,1字母,2符号,3数字+字母,4数字+符号,5字母+符号,6ok
signed main()
{
	int n,m,ans=inf;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int j=0;j<3;j++)
			dp[i][j]=inf;
		for(int j=0;j<m;j++)
		{
			char &ch=s[i][j];
			if(isdigit(ch))
				dp[i][0]=min(dp[i][0],j);
			else if(isalpha(ch))
				dp[i][1]=min(dp[i][1],j);
			else
				dp[i][2]=min(dp[i][2],j);
		}
		for(int j=m-1,k=1;j>=0;j--,k++)
		{
			char &ch=s[i][j];
			if(isdigit(ch))
				dp[i][0]=min(dp[i][0],k);
			else if(isalpha(ch))
				dp[i][1]=min(dp[i][1],k);
			else
				dp[i][2]=min(dp[i][2],k);
		}
//		for(int j=0;j<=6;j++)
//			cout<<dp[i][j]<<' ';
//		cout<<endl;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(i!=j&&j!=k)
					ans=min(ans,dp[i][0]+dp[j][1]+dp[k][2]);
	cout<<ans<<endl;
	return 0;
}
signed abandon()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	memset(dp,inf,sizeof(dp));
	int n,m,ans=0;
	cin>>n>>m;
	//0数字,1字母,2符号,3数字+字母,4数字+符号,5字母+符号,6ok
	for(int i=0;i<=2;i++)
		dp[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int j=0;j<m;j++)
		{
			char &ch=s[i][j];
			if(isdigit(ch))
			{
				dp[i][0]=min(dp[i][0],dp[i-1][0]+j);
				dp[i][3]=min(dp[i][3],min(dp[i-1][3]+j,dp[i-1][1]+j));
				dp[i][4]=min(dp[i][4],min(dp[i-1][4]+j,dp[i-1][2]+j));
				dp[i][6]=min(dp[i][6],min(dp[i-1][6]+j,dp[i-1][5]+j));
			}
			else if(isalpha(ch))
			{//是字母
				dp[i][1]=min(dp[i][1],dp[i-1][1]+j);
				dp[i][3]=min(dp[i][3],min(dp[i-1][3]+j,dp[i-1][0]+j));
				dp[i][5]=min(dp[i][5],min(dp[i-1][5]+j,dp[i-1][2]+j));
				dp[i][6]=min(dp[i][6],min(dp[i-1][6]+j,dp[i-1][4]+j));
			}
			else{
				dp[i][2]=min(dp[i][2],dp[i-1][2]+j);
				dp[i][4]=min(dp[i][4],min(dp[i-1][4]+j,dp[i-1][0]+j));
				dp[i][5]=min(dp[i][5],min(dp[i-1][5]+j,dp[i-1][1]+j));
				dp[i][6]=min(dp[i][6],min(dp[i-1][6]+j,dp[i-1][3]+j));
			}
		}
		for(int j=0;j<=6;j++)
			cout<<dp[i][j]<<' ';
		cout<<endl;
	}
	cout<<dp[n][6]<<endl;
	return 0;
}


