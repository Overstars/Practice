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
char s[maxn],t[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m;
//	cin>>t;
//	while(t--)
	{
		cin>>n>>m>>s+1>>t+1;
		int pos=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='*')
			{
				pos=i;
				break;
			}
		bool ok=0;
		if(pos==0&&strcmp(s+1,t+1)==0)
			ok=1;
		if(pos&&n<=m+1)
		{
			bool diff=0;
			for(int i=1;i<pos;i++)
			{
				if(s[i]!=t[i])
					diff=1;
			}
			for(int i=1,cnt=n-pos;cnt>0;cnt--,i++)
			{
				if(s[n-i+1]!=t[m-i+1])
					diff=1;
			}
			if(!diff)
				ok=1;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
	return 0;
}
/*
 * 2021-05-07-14.11.50
*/

