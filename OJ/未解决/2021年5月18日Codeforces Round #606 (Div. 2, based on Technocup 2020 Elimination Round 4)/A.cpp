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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ans=0,tmp=n,cnt=0,MIN=10,f;
		while(tmp)
		{
			if(tmp<10)
				f=tmp;
			else
				MIN=min(MIN,tmp%10);
			tmp/=10;
			cnt++;
		}
		ans=9*(cnt-1)+f-1+(MIN>=f?1:0);
		ans=9*(cnt-1);//+f-1+(MIN>=f?1:0);
		tmp=1;
		for(int i=1;i<cnt;i++)
			tmp=tmp*10+1;
		int st=tmp;
		while(st<=n)
		{
			ans++;
			st+=tmp;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
 * 2021-05-18-12.34.21
 * 120
 * 119
*/

