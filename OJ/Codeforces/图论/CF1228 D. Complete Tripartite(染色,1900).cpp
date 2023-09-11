//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
vector<int>G[maxn];
int col[maxn],vis[maxn],cnt[4];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int &v:G[1])
		col[v]=2;
	for(int i=1;i<=n;i++)
		if(col[i]==0)//集合1
			col[i]=1,cnt[1]++;
	for(int i=1;i<=n;i++)
		if(col[i]==2)
		{
			for(int &v:G[i])//确定集合3
				if(col[v]!=1)
					col[v]=3,cnt[3]++;
			break;
		}
	cnt[2]=n-cnt[1]-cnt[3];
	bool ok=1;
	if(m!=cnt[1]*cnt[2]+cnt[2]*cnt[3]+cnt[1]*cnt[3]||(m<3))
		ok=0;
	if(cnt[1]==0||cnt[2]==0||cnt[3]==0)
		ok=0;
	for(int i=1;i<=n;i++)
		for(int &v:G[i])
			if(col[i]==col[v])
				ok=0;
	if(ok)
		for(int i=1;i<=n;i++)
			cout<<col[i]<<' ';
	else
		cout<<-1<<endl;
	return 0;
}
/*
 *思考:任选一个节点相邻节点染色,未染上色的节点分到同一个集合
 *任选一个染色节点,对其相邻染色节点进行染色,标记为颜色3
 *三个集合就分好了
 *然后检查是否成立,相同集合之间是否有边
 *直接暴力check就好了，又不是完全图...
 */

