#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=5005,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int gcd(int a,int b)
{
	if(a<b)
		swap(a,b);
	int r;
	while((r=a%b)){
		a=b;
		b=r;
	}
	return b;
}
int a[maxn][maxn],MAX[maxn][maxn];
int q[maxn],fr,tail;
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=i/gcd(i,j)*j;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			printf("%4d%c",a[i][j],(j==m)?'\n':' ');
	for(int i=1;i<=n;i++)
	{//每一行用单调队列维护[i-k+1,i]的最大值
		fr=1,tail=0;
		for(int j=1;j<=m;j++)
		{//每行维护一个递减队列
			while(fr<=tail&&a[i][q[tail]]<=a[i][j])
				tail--;
			q[++tail]=j;
			while(fr<=tail&&q[fr]<=j-k)
				fr++;
			if(j>=k&&fr<=tail)
				MAX[i][j-k+1]=a[i][q[fr]];
		}
	}
	for(int i=1;i<=m;i++)//i列
	{
		fr=1,tail=0;
		for(int j=1;j<=n;j++)//j行
		{
			while(fr<=tail&&MAX[q[tail]][i]<=MAX[j][i])
				tail--;
			q[++tail]=j;//下标入队
			while(fr<=tail&&q[fr]<=j-k)//队首不在范围内
				fr++;
			if(j>=k&&fr<=tail)
				MAX[j-k+1][i]=MAX[q[fr]][i];
		}
	}
	ll ans=0;
	for(int i=1;i+k-1<=n;i++)
		for(int j=1;j+k-1<=m;j++)
			ans+=MAX[i][j];
	printf("%lld\n",ans);
	return 0;
}


