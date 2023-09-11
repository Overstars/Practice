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
bool equ(double x,double y)
{
	if(abs(x-y)<1e-6)
		return 1;
	return 0;
}
double dfs(double a,double b)
{
	if((a<=b&&a>=0)||(a>=b&&a<=0))//同侧且a在内侧
		return abs(b-a);
//	if((a>b&&b>0&&a>1)||(a<b&&b<0&&a<-1))//同侧且外侧
//		return min(dfs(pow(a,(double)1/3),b)+1,abs(a-b));
	if(abs(a)>2)//&&(a*b<0||(a>b&&b>0)||(a<b&&b<0))
	{
		if(a<0)
		{
			printf("a=%f,b=%f,pow[%f]=%f\n",a,b,a,-pow(-a,(double)1/3));
			return min(dfs(-pow(-a,(double)1/3),b)+1,abs(a-b));
		}
		return min(dfs(pow(a,(double)1/3),b)+1,abs(a-b));
	}
	return abs(b-a);
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t;
	double a,b;
//	for(int i=1;i<=100;i++)
//	{
//		printf("s[%d]=%.9f\n",-i,-pow(i,(double)1/3));
//	}
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a<0)
		{
			a=-a,b=-b;
		}
		double ans=0;
		while(abs(pow(a,(double)1/3)-b)+1<abs(a-b))
		{
			ans+=1;
			a=pow(a,(double)1/3);
		}
		cout<<setiosflags(ios::fixed)<<setprecision(9)<<ans+abs(a-b)<<endl;
	}
	return 0;
}


