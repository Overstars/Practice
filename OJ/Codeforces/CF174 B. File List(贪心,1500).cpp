#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
char s[maxn];
int dp[maxn];
int get(int len)
{
	if(len<2||len>11)
		return 0;
	if(len>=4)
		return 3;//多拿
	return 1;//1+(len-1)
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
//		freopen("output.out", "w", stdout);
	#endif
	bool ok=1,flag=0;
	cin>>s+1;
	int n=strlen(s+1),now,cnt=0,pre=0,i=1;
	if(s[1]=='.'||s[n]=='.')
		ok=0;
	vector<string>ans;
	for(i=1,now=0;i<=n;i++)
	{
		if(s[i]!='.')
			now++;
		if(now>11||(pre==0&&now>8))
		{
			ok=0;
			break;
		}
		if(pre==0&&s[i]=='.')
		{
			pre=i;
			now=0;
			continue;
		}
		if(pre&&s[i]=='.')
		{//dp[i]表示第i个子串的末尾下标
			if(now<2)
				ok=0;
			dp[++cnt]=pre+get(now);
			pre=i;
			break;
		}
		if(i==n)
		{
			if(now>3||pre==0)
				ok=0;
			dp[++cnt]=n;
		}
	}
	i++;
	for(int now=0;i<=n;i++)
	{//1~8.1~3
		if(s[i]!='.')
			now++;
		if(now>11||(i==n&&(now>3||s[n]=='.')))
		{
			ok=0;
			break;
		}
		if(i==n)
		{
			dp[++cnt]=n;
			break;
		}
		if(s[i]=='.')
		{
			if(now<2)
			{
				ok=0;
				break;
			}
			dp[++cnt]=pre+get(now);
			now=0;
			pre=i;
		}
	}
	cout<<(ok?"YES":"NO")<<endl;
	if(ok)
	{
		int j=1;
		for(int i=1;i<=cnt;i++)
		{
			for(;j<=dp[i];j++)
				cout<<s[j];
			cout<<endl;
		}
	}
	return 0;
}


