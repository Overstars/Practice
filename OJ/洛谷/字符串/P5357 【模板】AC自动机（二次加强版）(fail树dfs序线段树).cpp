//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=5e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
struct BinaryIndexedsTree
{
	int n;
	ll c[maxn],sum[maxn];//c维护差分数组,sum维护i*c[i]的前缀和
	inline int lowbit(int x)
	{
		return x & (-x);
	}
	void build(int *a,int n)//a是原数组,n是元素个数
	{
		this->n=n;
		memset(c,0,sizeof(c));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
			add(i,a[i]-a[i-1]);//构建差分c数组
	}
	void add(int k,ll val)//修改:a[k]加上val,直接在c数组上操作
	{//请使用区间更新
		for(int i=k;i<=n;i+=lowbit(i))//从叶子一直更新到父节点
			c[i]+=val,sum[i]+=val*(k-1);//每个节点都加上val
	}
	void radd(int l,int r,ll val)//区间更新
	{
		add(l,val);//把l之后所有的点都更新一遍
		add(r+1,-val);//因为r之后的点是不用更新的,但是多更新了,所以要每个点都-val；
	}
	ll query(int k)//查询:c[i]前缀和的前缀和,即a[i]的前缀和
	{//节点i的长度为lowbit(i)
		ll ret=0;
		for(int i=k;i;i-=lowbit(i))
			ret+=k*c[i]-sum[i];
		return ret;
	}
} bit;
const int  M = 26;
struct AhoCorasickAutomaton
{
	int trie[maxn][M],isw[maxn],fail[maxn],siz;
	void init()//fail指向当前状态的最长后缀状态
	{
		siz=1;
		memset(trie[0],0,sizeof(trie[0]));
		memset(isw,0,sizeof(isw));
	}
	inline int mp(const char &ch)
	{
		return (int)(ch-'a');
	}
	int Insert(string &str)//rt传入0
	{//trie插入模式串
		int rt=0;
		for(int i=0;i<str.length();i++)
		{
			int id = mp(str[i]);
			if(!trie[rt][id])
			{
				memset(trie[siz],0,sizeof(trie[siz]));
				trie[rt][id]=siz++;
			}
			rt = trie[rt][id];
		}
		isw[rt]++;//标记这个点为结尾
		return rt;//返回
	}
	vector<int>G[maxn];
	void build()//构造fail指针
	{
		queue<int> Q;
		fail[0]=0;
		for(int id=0,rt;id<M;id++)
		{
			rt=trie[0][id];
			if(rt)//将根节点子节点入队
			{
				Q.push(rt);
				fail[rt]=0;
			}
		}
		while(!Q.empty())
		{
			int rt=Q.front();//fail[rt]在之前已构建完毕
			Q.pop();
			for(int id=0;id<M;id++)//枚举所有子节点
			{
				int v=trie[rt][id];
				if(v)//该号子节点存在
				{
					fail[v]=trie[fail[rt]][id];
					Q.push(v);
				}
				else//将不存在的字典树的状态链接到了失配指针的对应状态
					trie[rt][id]=trie[fail[rt]][id];//文本串可能访问未知节点
			}
		}
		for(int i=1;i<siz;i++)//构建fail树,根为0
		{
			G[fail[i]].push_back(i);
//			fprintf(stderr,"%d -> %d\n",fail[i],i);
		}
	}
	int query(string &str)
	{//返回文本串中有多少模式串(一个模式串只记录一次答案)
		int ret=0,rt=0;
		for(char &i:str)
		{
			rt=trie[rt][mp(i)];
			for(int tmp=rt;tmp&&~isw[tmp];tmp=fail[tmp])
				ret+=isw[tmp],isw[tmp]=-1;//用fail找出所有匹配模式串
		}//匹配成功的不会再匹配
		return ret;
	}
	int dfn[maxn],node[maxn],dfc=0;
	int dfs(int x,int fa)
	{
		dfn[x]=++dfc;
//		fprintf(stderr,"dfn[%d] = %d\n",x,dfn[x]);
		node[x]=1;
		for(auto &v:G[x])
			node[x]+=dfs(v,x);
		return node[x];
	}
} ac;
int tr[maxn][M];
int get(int x)
{//dfs序树上子树权值和
	return bit.query(ac.dfn[x]+ac.node[x]-1)-bit.query(ac.dfn[x]-1);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ac.init();
	int n;
	cin>>n;
//	vector<string> rec(n);
	string s;
	vector<int>rec2;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		rec2.push_back(ac.Insert(s));
	}
	bit.n=ac.siz+10;
	memcpy(tr[0],ac.trie[0],sizeof(int)*maxn*M);//之前建fail树会损坏trie
	ac.build();
	ac.dfs(0,0);
	cin>>s;
	int rt=0;
	#define mp(ch) (int)(ch-'a')
	for(auto &i:s)
	{
		while(!tr[rt][mp(i)]&&rt)
			rt=ac.fail[rt];
		rt=tr[rt][mp(i)];//访问到了trie上以i结尾这个点
//		fprintf(stderr,"now = %d,\n",ac.dfn[rt]);
		bit.radd(ac.dfn[rt],ac.dfn[rt],1);//这个状态被匹配一次,
	}
	for(auto &i:rec2)
		cout<<get(i)<<endl;
	return 0;
}
/*
 * 2021-06-01-20.35.03
 * C:\Users\dell\Desktop\C++\OJ\洛谷\字符串\P5357 【模板】AC自动机（二次加强版）(fail树dfs序线段树).cpp
 * 在fail树上做文章
 * 这个modify单点修改,对于一个点,他子树上匹配点的总数即为这个点的匹配数
*/

