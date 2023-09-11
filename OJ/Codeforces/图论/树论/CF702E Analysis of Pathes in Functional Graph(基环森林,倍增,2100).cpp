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
int v[maxn],w[maxn];
const int lg=35;
int gene[maxn][lg],Fsum[maxn][lg],Fmin[maxn][lg];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>v[i],gene[i][0]=v[i];
	for(int i=0;i<n;i++)
		cin>>w[i],Fsum[i][0]=Fmin[i][0]=w[i];
	for(int i=1;i<35;i++)
	{
		for(int x=0;x<n;x++)
		{//x向后2^i的点
			int nex=gene[x][i-1];
			gene[x][i]=gene[nex][i-1];
			Fsum[x][i]=Fsum[x][i-1]+Fsum[nex][i-1];
			Fmin[x][i]=min(Fmin[x][i-1],Fmin[nex][i-1]);
		}
	}
	for(int i=0;i<n;i++)
	{
		int qsum=0,qmin=INF,x=i;
		for(int j=34;j>=0;j--)
		{
			if(k&(1ll<<j))
			{
				qsum+=Fsum[x][j];
				qmin=min(qmin,Fmin[x][j]);
				x=gene[x][j];
			}
		}
		cout<<qsum<<' '<<qmin<<endl;
	}
	return 0;
}
/*
 *边有边权,求从点x出发接下来的k条边权值和以及最小边权
 *首先图上一定有至少一个环
 *且每个点出发接下来去的点一定唯一确定
 *似乎要用线段树维护,如何操作
 *不会,看题解说是倍增
 *从某点开始,若向后查询长度很长,且路径唯一,可以考虑倍增优化
 *复杂度nlogk
*/

