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
int c[maxn],ans=inf,n,a,b;
set<pii>vis;
void dfs(int x,int y,int d)
{
	if(x>y)
		swap(x,y);
	if(d>n+1||d>ans||vis.count(pii(x,y)))
		return;
//	cerr<<"x = "<<x<<", y = "<<y<<endl;
	vis.insert(pii(x,y));
	if(x>=a&&y>=b)
	{
		ans=min(ans,d-1);
		return;
	}
	if(x<b)
		dfs(x*c[d],y,d+1);
	if(y<b)
		dfs(x,y*c[d],d+1);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int h,w;
	cin>>a>>b>>h>>w>>n;
	if(a>b)
		swap(a,b);
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+n+1,greater<int>());
	dfs(h,w,1);
	cout<<(ans==inf?-1:ans)<<endl;
	return 0;
}
/*
 *2021-04-08-20.09.36
 *https://www.luogu.com.cn/problem/CF799D
*/

