//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
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
int n,m,p;
double f(int x)
{
	double ret=n*x+m;
	double tmp=1-pow((double)p/10000,x);
	return ret/tmp;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t;
	read(t);
	while(t--)
	{
		read(n,m,p);//
		p=10000-p;
		int l=1,r=1e9+10,ll=1,rr=1e9+10;
		double ans=1e18;
		while(l<r)
		{
			int mid1=l+(r-l)/3;
			int mid2=r-(r-l)/3;
			if(f(mid1)<f(mid2))
				r=mid2;
			else
				l=mid1;
//			fprintf(stderr,"m1 = %d, m2 = %d\n",mid1,mid2);
//			fprintf(stderr,"f(%d) = %.4f\n",mid1,f(mid1));
//			fprintf(stderr,"f(%d) = %.4f\n",mid2,f(mid2));
			double now=min(f(mid1),f(mid2));
			ans=min(ans,now);
			if(ll==l&&rr==r)
				break;
			ll=l;
			rr=r;
//			ans=min(ans,));
		}
		printf("%.8f\n",ans);
	}
	return 0;
}
/*
999
1 1 1
1 1 5000
1 2 10000
*/
/*
 * 2021-06-04-15.24.08
 * C:\Users\dell\Desktop\2021年6月4日2020-2021 ACM-ICPC, Asia Nanjing Regional Contest (XXI Open Cup, Grand Prix of Nanjing)\F.cpp
 *
*/

