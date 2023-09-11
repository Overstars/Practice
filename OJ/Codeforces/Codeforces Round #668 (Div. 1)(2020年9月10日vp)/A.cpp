//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
#define ff first
#define ss second
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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,k;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>s;
		bool ok=1;
		set<int>s0,s1;
		for(int i=0;i<n;i++)
			if(s[i]=='0')
				s0.insert(i%k);
			else if(s[i]=='1')
				s1.insert(i%k);
		for(auto &x:s0)
			for(int i=0;i*k+x<n;i++)
			{
				if(s[i*k+x]=='1')
					ok=0;
				else
					s[i*k+x]='0';
			}
		for(auto &x:s1)
			for(int i=0;i*k+x<n;i++)
			{
				if(s[i*k+x]=='0')
					ok=0;
				else
					s[i*k+x]='1';
			}
		int c0=0,c1=0;
		for(int i=0;i<k;i++)
			if(s[i]=='0')
				c0++;
			else if(s[i]=='1')
				c1++;
		if(max(c0,c1)>k/2)
			ok=0;
		cout<<(ok?"YES":"NO")<<endl;
	}
	return 0;
}
/*
3
3 2
1?0
4 2
1??1
*/

