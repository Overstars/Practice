#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,inf=0x3f3f3f3f;
struct edge
{
	int v,nex;
} e[maxn<<1];
int head[maxn],tot;
inline void add(int u,int v)
{
	e[++tot].v=v;
	e[tot].nex=head[u];
	head[u]=tot;
}
int depth[maxn],siz[maxn],son[maxn];
void dfs(int x,int fa)
{
	depth[x]=depth[fa]+1;
	siz[x]=1;
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa)
			continue;
		dfs(v,x);
		siz[x]+=siz[v];
		if(siz[son[x]]<siz[v])
			son[x]=v;
	}
}//cnt[i][j]表示绝对深度i,节点种类j个数
int n,m,flag,col[maxn],cnt[maxn][27];
vector<pair<int,int> >query[maxn];
bool ans[maxn];
bool jud(int dep)
{
	bool odd=0;
	for(int i=1;i<=26;i++)
		if(cnt[dep][i]&1)
		{
			if(odd)//奇数大于1,不成立
				return 0;
			else
				odd=1;
		}
	return 1;
}
void solve(int x,int fa,int val)
{//暴力统计当前子树答案
	cnt[depth[x]][col[x]]+=val;//不能传入相对深度
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa||v==flag)
			continue;
		solve(v,x,val);
	}
}
void dfs(int x,int fa,bool keep)
{
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa||v==son[x])
			continue;
		dfs(v,x,0);
	}
	if(son[x])//处理所有轻儿子节点后,处理重儿子子树
	{
		dfs(son[x],x,1);
		flag=son[x];//标记当前重儿子,防止统计x及轻儿子时访问x的重儿子
	}
	solve(x,fa,1);//计算x树信息
	for(auto &i:query[x])
		if(!ans[i.second]&&jud(i.first))
			ans[i.second]=1;
	flag=0;
	if(!keep)//轻儿子不做保留,消去信息
	{//重儿子保留,回溯到上一级时
		solve(x,fa,-1);
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&u);
		add(u,i);
		add(i,u);
	}
	char ch;
	for(int i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		col[i]=(int)(ch-'a'+1);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		query[u].push_back(make_pair(v,i));//深度v,询问i
	}
	dfs(1,0);
	dfs(1,0,0);
	for(int i=1;i<=m;i++)
		printf("%s\n",ans[i]?"Yes":"No");
	return 0;
}
