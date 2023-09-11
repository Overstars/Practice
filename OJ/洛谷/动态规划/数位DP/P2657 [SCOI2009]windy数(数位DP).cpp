#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll dp[20][20];//dp[i][j]表示长度为i以j开头的windy数个数
void init()
{
	for(int i=0;i<=9;i++)
		dp[1][i]=1;
	for(int i=2;i<=10;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				if(abs(j-k)>=2)
					dp[i][j]+=dp[i-1][k];
			}
		}
	}
}
ll num[15];
ll solve(ll x)//计算[1,x]windy数
{
	ll ans=0,len=0;
	memset(num,0,sizeof(num));
	while(x)
	{
		num[++len]=x%10;//依次为x由低到高的位上的数
		x/=10;
	}
	for(int i=1;i<=len-1;i++)//长度小于len
	{
		for(int j=1;j<=9;j++)//以j开头
		{
			ans+=dp[i][j];
		}
	}
	for(int i=1;i<num[len];i++)
		ans+=dp[len][i];
	for(int i=len-1;i>=1;i--)//高位向低位枚举
	{//长度为len,以x的前几位开头
		for(int j=0;j<num[i];j++)//枚举这一位为j
		{//
			if(abs(num[i+1]-j)>=2)
				ans+=dp[i][j];
		}
		if(abs(num[i+1]-num[i])<2)//x本身不符合
			break;
	}
	return ans;//这样枚举不会包含自己
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	init();
	ll a,b;
	cin>>a>>b;
	cout<<solve(b+1)-solve(a)<<endl;
	return 0;
}


