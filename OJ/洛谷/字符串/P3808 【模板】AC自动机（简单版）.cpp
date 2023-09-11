#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005, M = 26;
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
	void Insert(const char *str)//rt传入0
	{//trie插入模式串
		int len=strlen(str),rt=0;
		for(int i=0;i<len;i++)
		{
			int id = mp(str[i]);
			if(!trie[rt][id])
			{
				memset(trie[siz],0,sizeof(trie[siz]));
				trie[rt][id]=siz++;
			}
			rt = trie[rt][id];
		}
		isw[rt]++;
	}
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
					trie[rt][id]=trie[fail[rt]][id];
			}
		}
	}
	int query(const char *str,int len)
	{//返回文本串中有多少模式串
		int ret=0,rt=0;
		for(int i=0;i<len;i++)
		{
			rt=trie[rt][mp(str[i])];
			for(int tmp=rt;tmp&&~isw[tmp];tmp=fail[tmp])
				ret+=isw[tmp],isw[tmp]=-1;
		}
		return ret;
	}
} ac;
char s[maxn];
int main()
{
//	freopen("P3808_2.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	scanf("%d",&n);
	ac.init();
	while(n--)
	{
		scanf("%s",s);
		ac.Insert(s);//模式串
	}
	ac.build();
	scanf("%s",s);
	printf("%d\n",ac.query(s,strlen(s)));
	return 0;
}
