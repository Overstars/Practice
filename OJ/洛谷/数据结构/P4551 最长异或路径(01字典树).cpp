//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
#define ff first
#define ss second
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007,M=2;
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
struct edge
{
	int v,w;
};
vector<edge>G[maxn];
int sum[maxn],ans=0;
int trie[maxn<<5][M],cnt[maxn<<5][M],isw[maxn],siz;
void Insert(const int key)//rt传入0
{//trie插入模式串
	int rt=0;
	cnt[rt][0]++;//这位肯定是0的
	for(int i=31;i>=0;i--)//固定向下31位
	{
		int id = (key>>i)&1;
		if(!trie[rt][id])
		{
//			memset(trie[siz],0,sizeof(trie[siz]));
			trie[rt][id]=siz++;//添加新节点
		}
		cnt[rt][id]++;//子节点多少个
		rt = trie[rt][id];//向下
	}
//	isw[rt]++;
}
int query(int key)
{
	int rt=0,ret=0;
//	cnt[rt][0]--;
	for(int i=31;i>=0;i--)
	{
		int nex=!((key>>i)&1);//最好是不同,异或值为1
		if(cnt[rt][nex]==0)//这种情况莫得了
			nex=!nex;//换较差的那种
		if(cnt[rt][nex]==0)//另一种也没有
			break;
		ret=(ret<<1)+nex;
//		cnt[rt][nex]--;//子节点数量减1
		rt=trie[rt][nex];//向下
	}
//	printf("key=%lld,ret=%lld\n",key,ret);
	return ret^key;
}
void dfs(int x,int fa)
{
	if(x>1)
		ans=max(ans,query(sum[x]));
//	printf("x=%lld,sum=%lld,ans=%lld\n",x,sum[x],ans);
	Insert(sum[x]);
	for(auto &e:G[x])
	{
		if(e.v==fa)
			continue;
		sum[e.v]=sum[x]^e.w;
		dfs(e.v,x);
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,u,v,w;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}


