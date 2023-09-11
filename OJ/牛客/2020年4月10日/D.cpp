#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=1e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct edge
{
	ll u,v,w;
	edge(ll u,ll v,ll w):
		u(u),v(v),w(w){}
} e[maxn<<1];
ll head[maxn],cnt=0;
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	memset(head,-1,sizeof(head));
	int n,m,u,v,w;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
	}
	return 0;
}


