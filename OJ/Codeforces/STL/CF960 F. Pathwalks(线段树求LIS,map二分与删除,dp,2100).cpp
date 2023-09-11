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
//struct edge
//{
//	int u,v,id,k;
//	edge(){}
//	edge(int u,int v,int id,int k):
//		u(u),v(v),id(id),k(k){}
//};
//vector<edge> rec,G[maxn];
//struct node
//{
//	int l,r,val;
//} tree[maxn<<2];
//inline void pushup(int root)
//{
//	tree[toot].val=tree[root<<1].val+tree[root<<1|1].val;
//}
map<int,int> dp[maxn];
int get(int x,int k)
{//二分得到以x结尾且边权小于k的位置
	int val=0;
	map<int,int>::iterator it=dp[x].lower_bound(k);//
	if(it!=dp[x].begin())
		val=(--it)->ss;//得到长度
	return val;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v,k,ans=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>k;
		int now=get(u,k)+1;
		ans=max(ans,now);
		if(now>get(v,k))
		{//长度需要更新
			map<int,int>::iterator it=dp[v].lower_bound(k),it2;
			dp[v][k]=now;
			for(it2=it;it2!=dp[v].end()&&it2->ss<=now;)
			{//将之前所有权值大于k且长度小于now的删除,保持偏序
				it2=dp[v].erase(it2);//返回下个位置
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *2021年2月28日14点20分
 *求一条编号和权值都严格递增的最长路的长度
 *一条路径上要求权值单调递增,顺序同样单调递增(默认左到右)
 *dp[i]=max(dp[j])+1,其中j.v=i.u且在i的前面
 *相当于附带条件的LIS
 *好神的数据结构题...
*/

