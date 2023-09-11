#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
long long qmod(long long a,long long b)  //快速幂
{
	long long ans=1;
	a=a%mod;
	while(b)
	{
		if(b&1==1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
ll h(const string &s)
{
	ll res=0;
	for(int i=0;i<6;i++)
		res=res*26+s[i]-'a';
	return res;
}
void prin(int x)
{
	printf("%d\n",x);
	if(x<0)
		return;
	if(0<=x<26)
	{
		putchar('a'+x);
//		cout<<'a'+x;
	}
	else{
		prin(x/26);
		putchar('a'+x%26);
	}
}
int main()
{
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll mod;
	ll lim=308915775;
	string s;
	while(cin>>s>>mod)
	{
		int now=h(s),st=now+mod;
//		while(st%mod!=now%mod&&st<lim)
//		{
//			st+=mod;
//		}
		if(st<lim)
		{
			string ans;
			for(int i=1,tmp=st;i<=6;i++)
			{
				ans.insert(0,1,(char)('a'+tmp%26));
				tmp/=26;
			}
			cout<<ans<<endl;
		}
		else
			cout<<-1<<endl;
	}
	return 0;
}


