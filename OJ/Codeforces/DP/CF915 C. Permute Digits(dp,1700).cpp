//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
int sum[maxn][10];
map<int,int>mp;
char s[20],t[20];
int check(int pos,bool &flag)
{
	int ans=0;
	for(int i=0;i<=9;i++)
		if(mp[i])
		{
			ans=i;
			break;
		}
	for(int i=t[pos]-'0';i>=0;i--)
	{//取走i之后s的位能否满足<=t
		bool ok=1;
		if(mp[i]==0)
		{
			ok=0;
			continue;
		}
		else if(i<t[pos]-'0')
		{
			ans=i;
			break;
		}
		string a;
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<mp[j]-(j==i?1:0);k++)
				a+=j+'0';
		}
		sort(a.begin(),a.end());
		for(int j=0;j<a.length();j++)
			if(a[j]!=t[pos+j+1])
			{
//				printf("a[%d]=%c,t[%d]=%c\n",j,a[j],pos+j+1,t[pos+j+1]);
				if(a[j]>t[pos+j+1])
					ok=0;
				break;
			}
//		cout<<"ok = "<<ok<<endl;
//		cout<<"pos = "<<pos<<", a = "<<a<<endl;
		if(ok)
		{
			ans=i;
			break;
		}
	}
	if(ans<t[pos]-'0')
		flag=1;
	mp[ans]--;
	return ans;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>s+1>>t+1;
	int n=strlen(s+1), m=strlen(t+1);
	for(int i=m;i>=1;i--)
	{
		sum[i][t[i]-'0']++;
		for(int j=9;j>=0;j--)
			sum[i][j]+=sum[i+1][j];
	}
	for(int i=1;i<=n;i++)
		mp[s[i]-'0']++;
	if(n<m)
	{
		sort(s+1,s+n+1,greater<char>());
		cout<<s+1<<endl;
	}
	else{//n=m
		string ans;
		for(int i=1;i<=n;i++)
		{
			bool flag=0;
			ans.push_back(check(i,flag)+'0');
			if(flag)
			{
				for(int j=9;j>=0;j--)
				{
					while(mp[j])
					{
						ans.push_back(j+'0');
						mp[j]--;
					}
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*

*/

