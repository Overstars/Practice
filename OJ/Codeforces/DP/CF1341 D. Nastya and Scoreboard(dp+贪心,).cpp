#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2005,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
char s[maxn][8],st[10][8]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
bool dp[maxn][maxn*7];//dp[i][j]:可用j根添加到[i,n]
int need[maxn][10];//预处理出第i个字符串变为j所需
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,tot;
	cin>>n>>tot;//tot个木棍
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
	{//将第i个串变为数字j所需代价
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=7;k++)
			{
				if(s[i][k]=='1'&&st[j][k]=='0')
				{//无法变为j
					need[i][j]=inf;
					break;
				}
				if(s[i][k]=='0'&&st[j][k]=='1')
					need[i][j]++;
			}
		}
	}
	dp[n+1][0]=1;
	for(int i=n;i>=1;i--)
	{//处理出可行解
		for(int j=0;j<=9;j++)
		{
			int inc=need[i][j];
			if(inc>=inf)
				continue;
			for(int k=inc;k<=tot;k++)
				dp[i][k]|=dp[i+1][k-inc];
		}
	}
	string ans;
	bool ok=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=9;j>=0;j--)
		{
			int now=need[i][j];//第i个数变为j的代价
			if(now>=inf)//为inf则无法变为j
				continue;
			if(dp[i+1][tot-now])
			{
				ok=1;//存在可行解
				tot-=now;
				ans+='0'+j;
				break;
			}
		}
		if(!ok)
			break;
	}
	if(ok)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
	return 0;
}


