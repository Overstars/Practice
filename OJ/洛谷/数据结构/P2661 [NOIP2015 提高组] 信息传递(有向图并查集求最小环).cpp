//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
int fa[maxn],d[maxn],ans=inf;
int findfa(int x)
{
	if(fa[x]!=x)
	{
		int last=fa[x];
		fa[x]=findfa(fa[x]);
		d[x]+=d[last];//更新路长
	}
	return fa[x];
}
void Merge(int x,int y)
{//
	int a=findfa(x),b=findfa(y);
	if(a!=b)
	{//不相连则连接,更新x的父节点为y
		fa[a]=b;
		d[x]=d[y]+1;//距离也要更新
	}
	else//相连
		ans=min(ans,d[x]+d[y]+1);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,u,v;
	cin>>n;
	for(int i=1;i<=n;i++)
		fa[i]=i,d[i]=0;
	for(int i=1;i<=n;i++)
	{//信息由u传给v
		Merge(u,v);
	}
	cout<<ans<<endl;
	return 0;
}


