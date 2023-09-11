//#pragma GCC optimize(2)
//#pragma G++ optimize("O2") //O2优化
//#pragma comment(linker, "/STACK:102400000,102400000") //手动扩栈
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<climits>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
//#define lowbit(x) ((x) & -(x))
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1005;
//#define DEBUG
//void read(){}
//template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
//	x=0; int ch=getchar(),f=0;
//	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
//	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
//	if(f)x=-x;
//	read(oth...);
//}
struct BinaryIndexedsTree2D
{
	#define lowbit(x) ((x) & -(x))
	int n,m;//行与列
	ll t1[maxn][maxn], t2[maxn][maxn], t3[maxn][maxn], t4[maxn][maxn];
	void add(ll x, ll y, ll z)
	{
		for(int i=x;i<=n;i+=lowbit(i))
			for(int j=y;j<=m;j+=lowbit(j))
			{
				t1[i][j]+=z;
				t2[i][j]+=z*x;
				t3[i][j]+=z*y;
				t4[i][j]+=z*x*y;
			}
	}
	void radd(ll xa,ll ya,ll xb,ll yb,ll z)
	{//(xa,ya)到(xb,yb)的矩形全部增加z
		add(xa,ya,z);
		add(xa,yb+1,-z);
		add(xb+1,ya,-z);
		add(xb+1,yb+1,z);
	}
	void build(int n,int m,ll a[][maxn])
	{
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		memset(t3,0,sizeof(t3));
		memset(t4,0,sizeof(t4));
		this->n=n,this->m=m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				radd(i,j,i,j,a[i][j]);
	}
	void build(int n,int m)
	{
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		memset(t3,0,sizeof(t3));
		memset(t4,0,sizeof(t4));
		this->n=n,this->m=m;
	}
	ll ask(ll x,ll y)
	{
		ll res = 0;
		for(int i=x;i;i-=lowbit(i))
			for(int j=y;j;j-=lowbit(j))
				res += (x + 1) * (y + 1) * t1[i][j]
					- (y + 1) * t2[i][j]
					- (x + 1) * t3[i][j]
					+ t4[i][j];
		return res;
	}
	ll query(ll xa, ll ya, ll xb, ll yb)
	{//查询(xa,ya)到(xb,yb)的矩形之和
		return ask(xb,yb)-ask(xb,ya-1)-ask(xa-1,yb)+ask(xa-1,ya-1);
	}
} b2d;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int t,n,q,x,y,x2,y2;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		if(i>1)
			putchar('\n');
		scanf("%d%d",&n,&q);
		b2d.build(n,n);
		while(q--)
		{
			char op;
			scanf(" %c",&op);
			if(op=='Q')
			{
				scanf("%d%d",&x,&y);
				printf("%d\n",b2d.query(x,y,x,y)%2);
			}
			else{
				scanf("%d%d%d%d",&x,&y,&x2,&y2);
				b2d.radd(x,y,x2,y2,1);
			}
		}
	}
	return 0;
}
