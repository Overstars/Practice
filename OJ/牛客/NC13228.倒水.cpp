//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
	ll n;
	double ma=0,mi=1e9+5;
	double T,C,ct=0,cc=0;
	cin>>n>>T>>C;
	for(int i=1;i<=n;i++)
	{
		double t,c;
		cin>>t>>c;
		ma=max(ma,t);
		mi=min(mi,t);
		cc+=c;
		ct+=t*c;
	}
	bool ok=1;
	double ans=(double)(1.0*T*C+ct)/(C+cc);
	if(ans>=ma)
		ans=ma;
	else if(ans<=mi)
		ans=mi;
	else
		ok=0;
	cout<<(ok?"Possible":"Impossible")<<endl;
	if(ok)
		cout<<setiosflags(ios::fixed)<<setprecision(4)<<ans<<endl;
	return 0;
}


