//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
int a[70],dp[20][20];
ll dfs(int pos,int sum,bool lead,bool limit)
{//dp[i][j]为进行到第i位,非0数为j的合法个数
	if(!limit&&!lead&&dp[pos][sum]>=0)
		return dp[pos][sum];
	if(sum==3)
		return 1;
	if(pos<1)//
		return sum<=3;
	int up=(limit?a[pos]:9),ret=0;
	for(int i=0;i<=up;i++)
	{
		if(i==0)
		{
			if(lead)//前导0,不是数字
				ret+=dfs(pos-1,0,lead,(limit&&i==up));
			else//0位
				ret+=dfs(pos-1,sum,lead,(limit&&i==up));
		}
		else{
			ret+=dfs(pos-1,sum+1,0,(limit&&i==up));
		}
	}
	if(!lead&&!limit)
		dp[pos][sum]=ret;
	return ret;
}
ll solve(ll x)
{
	memset(dp,-1,sizeof(dp));
	int top=0;
	while(x)
	{
		a[++top]=x%10;
		x/=10;
	}//合法:0>=len-3
	return dfs(top,0,1,1);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
//	for(int i=0;i<=30;i++)
//		fprintf(stderr,"dp[%d]=%lld\n",i,solve(i));
	int t,l,r;
	cin>>t;
	while(t--)
	{
		cin>>l>>r;
		try
		{
			if(l==0||r==0||l>r)
				throw l;
			cout<<solve(r)-solve(l-1)<<endl;
		}
		catch(int n)
		{
			cout<<"wtf = "<<n<<endl;
		}
	}
	return 0;
}
/*
 * 2021-04-15-09.12.23
*/

