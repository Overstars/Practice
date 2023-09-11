//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
#define ff first
#define ss second
const int maxn=104,inf=0x3f3f3f3f,mod=1000000007;
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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		int ans=0;
		for(int i=1;i<=n/2;i++)
			for(int j=1;j<=m/2;j++)
			{
//				int val=(a[i][j]+a[n-i+1][j]+a[i][m-j+1]+a[n-i+1][m-j+1])/4;
				vector<int>v;
				v.push_back(a[i][j]);
				v.push_back(a[n-i+1][j]);
				v.push_back(a[i][m-j+1]);
				v.push_back(a[n-i+1][m-j+1]);
				sort(v.begin(),v.end());
				int val=v[1];
				ans+=abs(a[i][j]-val)+abs(a[n-i+1][j]-val)+abs(a[i][m-j+1]-val)+abs(a[n-i+1][m-j+1]-val);
//				int now=abs(a[i][j]-val)+abs(a[n-i+1][j]-val)+abs(a[i][m-j+1]-val)+abs(a[n-i+1][m-j+1]-val);
//				val++;
//				now=min(now,abs(a[i][j]-val)+abs(a[n-i+1][j]-val)+abs(a[i][m-j+1]-val)+abs(a[n-i+1][m-j+1]-val));
//				ans+=now;
//				printf("(%lld,%lld)+(%lld,%lld)+(%lld,%lld)+(%lld,%lld)\n",i,j,n-i+1,j,i,m-j+1,n-i+1,m-j+1);
//				printf("(%lld,%lld)=%lld\n",i,j,now);
			}
		if(n&1)
		{
			int x=n/2+1;
			for(int j=1;j<=m/2;j++)
			{
//				int val=(a[x][j]+a[x][m-j+1])/2;
//				int now=abs(a[x][j]-val)+abs(a[x][m-j+1]-val);
//				val++;
//				now=min(now,abs(a[x][j]-val)+abs(a[x][m-j+1]-val));
				ans+=abs(a[x][j]-a[x][m-j+1]);
			}
		}
		if(m&1)
		{
			int y=m/2+1;
			for(int i=1;i<=n/2;i++)
			{
//				int val=(a[i][y]+a[n-i+1][y])/2;
//				int now=abs(a[i][y]-val)+abs(a[n-i+1][y]-val);
//				val++;
//				now=min(now,abs(a[i][y]-val)+abs(a[n-i+1][y]-val));
				ans+=abs(a[i][y]-a[n-i+1][y]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
99
3 3
1 2 3
4 5 6
7 8 9
*/

