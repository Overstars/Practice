//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
const int  M = 26;
struct AhoCorasickAutomaton
{
	int trie[maxn][M],isw[maxn],fail[maxn],siz;
	int id[maxn],cnt=0;
	void init()//fail指向当前状态的最长后缀状态
	{
		siz=1;
		cnt=0;
		memset(trie[0],0,sizeof(trie[0]));
		memset(isw,0,sizeof(isw));
		memset(id,0,sizeof(id));
	}
	inline int mp(const char &ch)
	{
		return (int)(ch-'a');
	}
	void Insert(string &str)//rt传入0
	{//trie插入模式串
		int rt=0;
		for(char &i:str)
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
		id[cnt++]=rt;//标记是哪个串
	}
	vector<int>G[maxn];
	void build()//构造fail指针
	{
		queue<int> Q;
		fail[0]=0;
		for(int id=0;id<M;id++)
		{
			int rt=trie[0][id];
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
				if(!v)
					continue;
				int tmp=fail[rt];
				while(!trie[tmp][id]&&tmp)
					tmp=fail[tmp];
				fail[v]=trie[tmp][id];
//				fprintf(stderr,"fail[%d] = %d\n",v,fail[v]);
				Q.push(v);
//				if(v)//该号子节点存在
//				{
//					fail[v]=trie[fail[rt]][id];
//					Q.push(v);
//				}
//				else//将不存在的字典树的状态链接到了失配指针的对应状态
//					trie[rt][id]=trie[fail[rt]][id];//文本串可能访问未知节点
			}
		}
//		for(int i=1;i<siz;i++)//构建fail树,根为0
//			G[fail[i]].push_back(i);
	}
	int query(string &str)
	{//返回文本串中有多少模式串(一个模式串只记录一次答案)
		int ret=0,rt=0;
		for(char &i:str)
		{
			while(!trie[rt][mp(i)]&&rt)
				rt=fail[rt];
			rt=trie[rt][mp(i)];
//			fprintf(stderr,"now = %c,rt = %d\n",i,rt);
			for(int tmp=rt;tmp&&~isw[tmp];tmp=fail[tmp])
				ret+=isw[tmp],isw[tmp]=-1;//用fail找出所有匹配模式串
		}//匹配成功的不会再匹配
		return ret;
	}
	int dfn[maxn],node[maxn],dfc=0;
	int dfs(int x,int fa)
	{
		dfn[x]=++dfc;
		node[x]=1;
		for(auto &v:G[x])
			node[x]+=dfs(v,x);
		return node[x];
	}
} ac;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	#ifdef DEBUG
		freopen("P3808_2.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
//	#endif
	int n;
	cin>>n;
	ac.init();
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		ac.Insert(s);
	}
	ac.build();
	cin>>s;
	cout<<ac.query(s)<<endl;
	return 0;
}
/*
 * 2021-06-01-22.22.57
 * C:\Users\dell\Desktop\C++\OJ\洛谷\字符串\P3808 【模板】AC自动机（简单版）(再写一遍).cpp
 * 会TLE
*/

