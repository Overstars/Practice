//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=1005,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn][maxn];
int q1[maxn],q2[maxn],h1,h2,t1,t2;
int b[maxn][maxn],c[maxn][maxn],b2[maxn][maxn],c2[maxn][maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,x;
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		h1=h2=1;
		t1=t2=0;
		for(int j=1;j<x;j++)
		{
			while(h1<=t1&&a[i][q1[t1]]<=a[i][j])
				t1--;
			q1[++t1]=j;
			while(h2<=t2&&a[i][q2[t2]]>=a[i][j])
				t2--;
			q2[++t2]=j;
		}
		for(int j=1;j<=m;j++)
		{//[j,j+x-1]
			if(j+x-1<=m)
			{
				while(h1<=t1&&a[i][q1[t1]]<=a[i][j+x-1])
					t1--;
				q1[++t1]=j+x-1;
				while(h2<=t2&&a[i][q2[t2]]>=a[i][j+x-1])
					t2--;
				q2[++t2]=j+x-1;
			}
			while(h1<=t1&&q1[h1]<j)
				h1++;
			while(h2<=t2&&q2[h2]<j)
				h2++;
			b[i][j]=a[i][q1[h1]];
			c[i][j]=a[i][q2[h2]];
		}
	}
	for(int i=1;i<=m;i++)
	{
		h1=h2=1;
		t1=t2=0;
		for(int j=1;j<x;j++)
		{
			while(h1<=t1&&b[q1[t1]][i]<=b[j][i])
				t1--;
			q1[++t1]=j;
			while(h2<=t2&&c[q2[t2]][i]>=c[j][i])
				t2--;
			q2[++t2]=j;
		}
		for(int j=1;j<=n;j++)
		{//[j,j+x-1]
			if(j+x-1<=n)
			{
				while(h1<=t1&&b[q1[t1]][i]<=b[j+x-1][i])
					t1--;
				q1[++t1]=j+x-1;
				while(h2<=t2&&c[q2[t2]][i]>=c[j+x-1][i])
					t2--;
				q2[++t2]=j+x-1;
			}
			while(h1<=t1&&q1[h1]<j)
				h1++;
			while(h2<=t2&&q2[h2]<j)
				h2++;
			b[j][i]=b[q1[h1]][i];
			c[j][i]=c[q2[h2]][i];
//			h1++,h2++;
		}
	}
	int ans=inf;
	for(int i=1;i<=n-x+1;i++)
		for(int j=1;j<=m-x+1;j++)
			ans=min(ans,b[i][j]-c[i][j]);
	cout<<ans<<endl;
	return 0;
}
/*
 *每行一个ST表,方便查询区间最大最小值
 *先对行处理出长度为n区域内的极值存入一个数组
 *再对该数组进行列上长度为n的单调队列维护
 *维护最大值需要单调递减
*/

