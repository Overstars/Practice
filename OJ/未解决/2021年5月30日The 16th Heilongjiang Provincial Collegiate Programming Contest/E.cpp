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
struct SegTree
{
	/*
	 * 动态开点线段树,可区间修改区间查询,能够处理零或负数位置
	 * 不需要build,用在没有提供初始数据的场合/强制在线无法离散化建树
	 * 默认初始值为0,有初始值可以单点修改
	*/
	using type = int;
	struct node
	{//
		int ls,rs;
		type val,mark,MAX;
		node(){}
		node(int l,int r,type v):
			ls(l),rs(r),val(v),MAX(v){mark=0;}
	} tree[maxn<<2];
	#define ls(x) tree[x].ls
	#define rs(x) tree[x].rs
	int cnt=1;
	const type NA = 0;
	static const int L=1,R=2e6+10;
	type pushup(type a,type b)
	{//修改之后的递归向上更新
		return a+b;
	}
	void update(int x,type d,int len)
	{//区间更新
		tree[x].val += d*len;
		tree[x].MAX += d;
		tree[x].mark += d;
	}
	void pushdown(int x,int len)
	{
		if(!ls(x))//左儿子不存在,创建新节点
			ls(x)=++cnt;
		if(!rs(x))//右儿子不存在
			rs(x)=++cnt;
		if(tree[x].mark!=NA)
		{
			update(ls(x),tree[x].mark,len/2);
			update(rs(x),tree[x].mark,len-len/2);
			tree[x].mark=NA;
		}
	}
	void assign(int l,int r,type val,int x=1,int cl=L,int cr=R)
	{//区间[l,r]推平,整体赋值为val
		if(cl>=l&&cr<=r)
		{
			tree[x].val=(cr-cl+1)*val;
			tree[x].mark=val;
			tree[x].MAX=val;
			return;
		}
		pushdown(x,cr-cl+1);
		int mid=(cl+cr-1)/2;
		if(mid>=l)
			assign(l,r,val,ls(x),cl,mid);
		if(mid<r)
			assign(l,r,val,rs(x),mid+1,cr);
		tree[x].val=pushup(tree[ls(x)].val,tree[rs(x)].val);//pushup操作
		tree[x].MAX=max(tree[ls(x)].MAX,tree[rs(x)].MAX);
	}
	void modify(int l,int r,type d,int x=1,int cl=L,int cr=R)
	{//目标区间[l,r],整体增加d,当前节点x,当前区间[cl,cr]
		if(cl>=l&&cr<=r)
			return update(x,d,cr-cl+1);//注意这个return
		pushdown(x,cr-cl+1);
		int mid=(cl+cr-1)/2;
		if(mid>=l)
			modify(l,r,d,ls(x),cl,mid);
		if(mid<r)
			modify(l,r,d,rs(x),mid+1,cr);
		tree[x].val=pushup(tree[ls(x)].val,tree[rs(x)].val);//pushup操作
		tree[x].MAX=max(tree[ls(x)].MAX,tree[rs(x)].MAX);
	}
	type querysum(int l,int r,int x=1,int cl=L,int cr=R)
	{//查询[l,r]区间权值和,当前节点x,当前区间[cl,cr]
		if(cl>=l&&cr<=r)//询问区间被当前区间包含
			return tree[x].val;
		pushdown(x,cr-cl+1);
		int mid=(cl+cr-1)/2;
		if(mid>=r)//在[cl,cr]的左半区间询问
			return querysum(l,r,ls(x),cl,mid);
		else if(mid<l)//在右半
			return querysum(l,r,rs(x),mid+1,cr);
		tree[x].MAX=max(tree[ls(x)].MAX,tree[rs(x)].MAX);
		return pushup(querysum(l,r,ls(x),cl,mid),querysum(l,r,rs(x),mid+1,cr));
	}
	type querymax(int l,int r,int x=1,int cl=L,int cr=R)
	{//查询区间[l,r]最大值
		if(cl>=l&&cr<=r)//[cl,cr]在询问区间内
			return tree[x].MAX;
		pushdown(x,cr-cl+1);
		int mid=(cl+cr-1)/2;
		if(mid>=r)
			return querymax(l,r,ls(x),cl,mid);
		else if(mid<l)//在右半
			return querymax(l,r,rs(x),mid+1,cr);
		tree[x].val=pushup(tree[ls(x)].val,tree[rs(x)].val);
		return max(querymax(l,r,ls(x),cl,mid),querymax(l,r,rs(x),mid+1,cr));
	}
	type ask4firstgreat(int l,int r,type val,int x=1,int cl=L,int cr=R)
	{//在区间[l,r]查询第一个>val的值的下标,当前区间[cl,cr]
		if(cl>cr)//越界
			return -1;
		if(cl==cr)//叶子
			return (tree[x].MAX>val?cl:-1);
		if(l<=cl&&cr<=r&&tree[x].MAX<=val)//该区间最值<=val,不存在
			return -1;
		pushdown(x,cr-cl+1);
		int mid=(cl+cr-1)/2,p=-1;
		if(l<=mid)//[cl,mid]与[l,r]有交集
			p=ask4firstgreat(l,r,val,ls(x),cl,mid);
		if(p==-1&&mid+1<=r)//左子树未找到,且[mid+1,cr]
			p=ask4firstgreat(l,r,val,rs(x),mid+1,cr);
		tree[x].val=pushup(tree[ls(x)].val,tree[rs(x)].val);//pushup操作
		tree[x].MAX=max(tree[ls(x)].MAX,tree[rs(x)].MAX);
		return p;
	}
	type ask4lastgreat(int l,int r,type val,int x=1,int cl=L,int cr=R)
	{//在区间[l,r]查询最后一个>val的值的下标,当前区间[cl,cr]
		if(cl>cr)
			return -1;
		if(cl==cr)
			return (tree[x].MAX>val?cl:-1);
		if(l<=cl&&cr<=r&&tree[x].MAX<=val)//该区间最值<=val,不存在
			return -1;
		pushdown(x,cr-cl+1);
		int mid=(cl+cr-1)/2,p=-1;
		if(mid+1<=r)
			p=ask4lastgreat(l,r,val,rs(x),mid+1,cr);
		if(p==-1&&l<=mid)
			p=ask4lastgreat(l,r,val,ls(x),cl,mid);
		tree[x].val=pushup(tree[ls(x)].val,tree[rs(x)].val);//pushup操作
		tree[x].MAX=max(tree[ls(x)].MAX,tree[rs(x)].MAX);
		return p;
	}
	#undef ls
	#undef rs
} T;
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
		for(auto &i:str)
		{
			int id = mp(i);
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
//		fprintf(stderr,"%d->%d\n",dfn[fa],dfn[x]);
//		fprintf(stderr,"dfn[%d] = %d\n",x,dfn[x]);
		node[x]=1;
		for(auto &v:G[x])
			node[x]+=dfs(v,x);
		return node[x];
	}
} ac;
int tr[maxn][M],dp[maxn],ans=0;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	vector<string> rec(n);
	vector<int> id;
	ac.init();
	for(auto &s:rec)
		cin>>s;
	sort(rec.begin(),rec.end(),[](const string &x,const string &y){
			return x.length()>y.length();
		});
	for(auto &s:rec)
		id.push_back(ac.Insert(s));
	memcpy(tr[0],ac.trie[0],sizeof(int)*maxn*M);
	ac.build();
	ac.dfs(0,0);
	#define mp(ch) (int)(ch-'a')
	for(int i=0;i<n;i++)
	{
//		cerr<<i<<" = "<<rec[i]<<", id = "<<id[i]<<endl;
//		cerr<<"l = "<<ac.dfn[id[i]]<<", r = "<<ac.dfn[id[i]]+ac.node[id[i]]-1<<endl;
		int now=T.querymax(ac.dfn[id[i]],ac.dfn[id[i]]+ac.node[id[i]]-1)+1;
//		cerr<<"query = "<<now<<endl;
		ans=max(ans,now);
		dp[i]=now;
		int rt=0;
		for(auto &ch:rec[i])
		{//将第i个串的每一个前缀都在fail树上更新答案,方便之后取子树最值
			while(!tr[rt][mp(ch)]&&rt)
				rt=ac.fail[rt];
			rt=tr[rt][mp(ch)];//访问到了trie上以i结尾这个点
			int pre=T.querymax(ac.dfn[rt],ac.dfn[rt]);//更新为新的dp值
			T.modify(ac.dfn[rt],ac.dfn[rt],now-pre);
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
3
bcba
cba
cba
*/
/*
 * 2021-05-30-12.14.13
 * C:\Users\dell\Desktop\C++\OJ\未解决\2021年5月30日The 16th Heilongjiang Provincial Collegiate Programming Contest\E.cpp
 * n个串,求一个最长序列,每一个串都是前面的串的子串
 * 若a为b的子串
 * 则b在trie上一定存在某一节点必定在a的fail子树上,将这些点插入的时候节点权值全部+1
 * bcd abcde ,则abcd在bcd的fail子树上
 * 因为我们必定可以通过去掉一个串的前缀与后缀来得到他的任意子串
 * 按照长度排序,dp[i]表示以第i个子串结尾的最长序列
 * 线段树维护子树上的最大dp值,将所有前缀节点都在fail(后缀)树上更新
*/

