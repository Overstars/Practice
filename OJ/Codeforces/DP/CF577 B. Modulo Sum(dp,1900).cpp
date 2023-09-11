//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	bool ok=0;
	int n,m;
	cin>>n>>m;
	set<int>dp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		set<int>tmp;
		for(auto &j:dp)
		{
			tmp.insert((a[i]+j)%m);
		}
		dp.insert(tmp.begin(),tmp.end());
		dp.insert(a[i]%m);
//		cerr<<"i = "<<i<<endl;
//		for(auto &x:dp)
//			cerr<<x<<' ';
//		cerr<<endl;
		if(dp.count(0))
		{
			ok=1;
			break;
		}
	}
	cout<<(ok?"YES":"NO")<<endl;
	return 0;
}
/*
 *2021-04-11-10.47.06
 *这个范围smg
*/

