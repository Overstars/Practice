#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll gcd(ll a,ll b)
{
	if(a<b)
		swap(a,b);
	ll r;
	while((r=a%b)){
		a=b;
		b=r;
	}
	return b;
}
ll exgcd(ll a,ll b,ll &x,ll &y)//扩展欧几里得,要保证a>b
{//传递x,y的引用
	if(b == 0)
	{//推理1，终止条件
		x = 1;
		y = 0;
		return a;//找到gcd,一路返回上去
	}
	ll r = exgcd(b, a%b, x, y);
	//先得到更底层的x2,y2,再根据计算好的x2,y2计算x1，y1。
	//推理2，递推关系x1=y2,y1=x2-(a/b)*y2;
	ll t = y;
	y = x - (a/b) * y;//(a/b)向下取整
	x = t;
//	printf("x1=%d,y1=%d,r=%d\n",x,y,r);
	return r;
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll a,b,c,k,ans[3];
	cin>>a>>b>>c>>k;
	for(int i=0;i*c<=k;i++)
	{
		ll ret=k-i*c;
		ans[2]=i;
		if(ret%gcd(a,b))
			continue;
		ll x0,y0;
		ll g=exgcd(a,b,x0,y0);
		ans[0]=((ret/g*x0)%(b/g)+(b/g))%(b/g);
		ans[1]=(ret-ans[0]*a)/b;
		if(ans[0]>=0&&ans[1]>=0)
			break;
	}
	for(int i=0;i<3;i++)
		cout<<ans[i]<<' ';
	return 0;
}


