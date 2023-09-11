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
double p(double a,int b)  //快速幂
{//qmod(a,p-2,p)
	double ans=1;
	while(b)
	{
		if(b&1)
			ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
double f(double x,double y)
{
	return 6*p(x,7)+8*p(x,6)+7*p(x,3)+5*p(x,2)-y*x;
}
double f1(double x,double y)
{//求导,可以发现这个先负后正
	return 42*p(x,6)+48*p(x,5)+21*p(x,2)+10*x-y;
}
double f2(double x,double y)
{//导数的导数
	return 252*p(x,5)+240*p(x,4)+42*x;
}
double getpos(double x,double y)
{//牛顿迭代法求f'(x)=0近似解
	while(abs(f1(x,y))>eps)
		x=x-f1(x,y)/f2(x,y);
	return x;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double y,ans=1e17;
		scanf("%lf",&y);
		for(int i=0;i<=100;i++)
		{
			double newpos=getpos(i,y);
			if(newpos>=0&&newpos<=100)
				ans=min(ans,f(newpos,y));
		}
		printf("%.4f\n",ans);
	}
	return 0;
}
/*
 *求出x在[0,100]上f(x)的最小值
 *迭代法不会死循环吗...
*/

