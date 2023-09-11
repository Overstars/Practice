//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
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
void print(__int128 x){
    if(x < 0){putchar('-');x=-x;}
    if(x > 9)print(x/10);
    putchar(x%10+'0');
}
__int128 d[maxn][20],sum[maxn],lg[maxn];
void init(__int128 *a,int n)
{//d[i][j]表示以i为起点,2^j长度的最值
	for(int i=1;i<=n;i++)
	{
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
		d[i][0]=a[i];
	}
	for(int j=1;(1<<j)<=n;j++)//枚举长度
		for(int i=1;i+(1<<j)-1<=n;i++)//枚举起点,倍增+DP
			d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
__int128 rmq(int l,int r)
{
	int k=lg[r-l+1];
	return max(d[l][k],d[r-(1<<k)+1][k]);
}
__int128 a[maxn],b[maxn];//利润,数量
signed main()
{
//	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	__int128 T,n;
	read(T);
//	scanf("%lld",&T);
	for(__int128 t=1;t<=T;t++)
	{
		read(n);
//		scanf("%lld",&n);
//		vector<__int128>
		for(__int128 i=1;i<=n;i++)
		{
			read(a[i]);
//			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i];//利润前缀和
		}
		init(sum,n);
		for(__int128 i=1;i<=n;i++)
		{
			read(b[i]);
//			scanf("%lld",&b[i]);//数量
			if(i>1)
				b[i]=min(b[i-1],b[i]);
		}
		ll cnt=0,pos=n;
		__int128 ans=0;
		while(cnt<b[1])
		{
			while(b[pos]<=cnt&&pos>1)//取光了这些
				pos--;
			ans+=rmq(1,pos)*(b[pos]-cnt);
			cnt=b[pos];
//			printf("pos=%lld,ans=%lld\n",pos,ans);
		}
		printf("Case #");
		print(t);
		printf(": ");
//		putchar(' ');
		print(b[1]);
		putchar(' ');
		print(ans);
		if(t<T)
			putchar('\n');
	}
	return 0;
}
/*
1
8
9 -4 8 15 17 -9 51 -14
9 4 7 2 4 8 3 1
*/

