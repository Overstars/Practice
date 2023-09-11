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
	int t=1,n,x1,x2,y1,y2,x,y;
//	cin>>t;
	while(t--)
	{
		cin>>x1>>y1>>x2>>y2>>x>>y;
		bool ok=1;
		int d1=abs(x1-x2),d2=abs(y1-y2);
		if(d1%x||d2%y)
			ok=0;
		else{
			int c1=d1/x,c2=d2/y;
			if((c1%2)!=(c2%2))
				ok=0;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
	return 0;
}
/*
 *2021-04-07-16.18.04
*/

