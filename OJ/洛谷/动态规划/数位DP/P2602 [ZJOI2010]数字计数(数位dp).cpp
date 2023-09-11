//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
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
ll a[maxn],dp[20][20];
ll dfs(ll pos,int statu,ll sum,bool limit,bool lead)
{//当前位置pos,limit=1是否受限,lead=0表示没有前导0
	if(pos<=0)//sum为前pos位statu出现的次数
		return sum;
	if(!limit&&dp[pos][sum]!=-1)
		return dp[pos][sum];
	ll up=(limit?a[pos]:9),ret=0;//当前上限
//	fprintf(stderr,"p = %d\n",pos);
	for(int i=0;i<=up;i++)
	{
		if(i==0&&lead)
		{//有前导0且该位还是前导零
			ret+=dfs(pos-1,statu,sum,limit&&(i==up),1);
		}
		else if(i&&lead)
		{//有前导0但该位不是前导0
			ret+=dfs(pos-1,statu,sum+(i==statu),limit&&(i==up),0);
		}
		else//没有前导0,
			ret+=dfs(pos-1,statu,sum+((!lead)&&i==statu),limit&&(i==up),0);
	}
	if(!limit&&!lead)
		dp[pos][sum]=ret;
	return ret;
}
ll solve(ll x,int y)
{
	int len=0;
	while(x)
	{
		a[++len]=x%10;
		x/=10;
	}
	memset(dp,-1,sizeof(dp));
	return dfs(len,y,0,1,1);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll a,b;
	cin>>a>>b;
	for(int i=0;i<=9;i++)
		cout<<solve(b,i)-solve(a-1,i)<<' ';
	return 0;
}
/*
 * 2021-04-16-08.55.32
*/

