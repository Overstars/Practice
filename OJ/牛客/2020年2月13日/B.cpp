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
struct node
{
	int x,y;
} a[maxn];
double dis(double p,int xx)
{
	return sqrt((a[xx].x-p)*(a[xx].x-p)+a[xx].y*a[xx].y);
}
double mindis=1e9;
bool check(double p,int n)
{
	double maxc=0;
	int rec=0;
	for(int i=1;i<=n;i++)
	{
		double now=dis(p,i);
		if(now>maxc)
		{
			rec=i;
			maxc=now;
		}
	}
	mindis=min(mindis,maxc);
	if(a[rec].x<p)
		return 0;//p向左
	return 1;
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
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1,[](const node&a,const node &b){
			return a.x<b.x;
		});
	double l=-10000,r=10000,mid;
//	mindis=max(dis(0,1),dis(0,n));
	while(!equ(l,r))
	{
		mid=(l+r)/2;
		if(check(mid,n))
			l=mid;//p向右
		else
			r=mid;
	}
	cout<<mindis<<endl;
	return 0;
}


