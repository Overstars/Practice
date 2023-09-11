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
	int t;
	cin>>t;
	while(t--)
	{
		vector<pii>rec(4);
		vector<int> p(4);
		iota(p.begin(),p.end(),0);
		for(auto &i:rec)
			cin>>i.ff>>i.ss;
		ll ans=INF;
		do{
			ll x1=min(rec[p[0]].ff,rec[p[1]].ff),x2=max(rec[p[0]].ff,rec[p[1]].ff);
			ll x3=min(rec[p[2]].ff,rec[p[3]].ff),x4=max(rec[p[2]].ff,rec[p[3]].ff);
			ll xl=x3-x2,xr=x4-x1;
			ll y1=min(rec[p[0]].ss,rec[p[3]].ss),y2=max(rec[p[0]].ss,rec[p[3]].ss);
			ll y3=min(rec[p[1]].ss,rec[p[2]].ss),y4=max(rec[p[1]].ss,rec[p[2]].ss);
			ll yl=y3-y2,yr=y4-y1;
//			if(xl<0||yl<0)
//				continue;
			ll cx=x2-x1+x4-x3;
			ll cy=y4-y3+y2-y1;
			if(yr>=xl&&xr>=yl)
				ans=min(ans,cx+cy);
			else
				ans=min(ans,cx+cy+min(abs(yl-xr),abs(xl-yr))*2);
		}while(next_permutation(p.begin(),p.end()));
		cout<<ans<<endl;
	}
	return 0;
}
/*
 * 2021-05-24-11.44.57
 * C:\Users\dell\Desktop\C++\OJ\Codeforces\数学\CF1455 E. Four Points(中位数,正方形,2400).cpp
 *
*/

