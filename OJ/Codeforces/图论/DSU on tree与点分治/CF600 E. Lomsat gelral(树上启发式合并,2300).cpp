#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
int head[maxn],tot;
struct Edge
{
	int v,nex;
} e[maxn<<1];
inline void add(int u,int v)
{
	e[++tot].v=v;
	e[tot].nex=head[u];
	head[u]=tot;
}
int siz[maxn],son[maxn];//记录当前节点的重儿子
void dfs(int x,int fa)//找重儿子
{
	siz[x]=1;
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa)
			continue;
		dfs(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])
			son[x]=v;
	}
}
int color[maxn],cnt[maxn];//存放各个节点颜色,cnt存放当前树中各颜色数量
ll ans[maxn],sum;//答案数组,当前子树答案
int flag,maxc;//标记重儿子,更新最大color数量
void cal(int x,int fa,int val)//暴力更新x节点及其轻儿子子树贡献
{//val=1表示增加贡献,-1表示消去贡献
	cnt[color[x]]+=val;
	if(cnt[color[x]]>maxc)
	{
		sum=color[x];//更新数量最多的颜色之和
		maxc=cnt[color[x]];
	}
	else if(cnt[color[x]]==maxc)
		sum+=color[x];//颜色之和
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa||v==flag)
			continue;
		cal(v,x,val);
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
	cal(x,fa,1);//处理x节点自身颜色
	ans[x]=sum;
	flag=0;//置0,防止影响计算
	if(!keep)//轻儿子不做保留,消去信息
	{//重儿子保留,回溯到上一级时
		cal(x,fa,-1);//这么写复杂度会低些
//		memset(cnt,0,sizeof(cnt));
		sum=maxc=0;
	}
}
int main()//求每个子树上出现次数最多的数字之和
{
	memset(head,-1,sizeof(head));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>color[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	dfs(1,0,0);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}
