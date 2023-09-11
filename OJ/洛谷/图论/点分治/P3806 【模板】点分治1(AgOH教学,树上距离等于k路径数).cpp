#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10005;
const int maxk=10000005;
int tot=0,head[maxn];
struct edge
{
	int v,nex,w;
} e[maxn<<1];
inline void add(int u,int v,ll w)
{
	e[++tot].v=v;
	e[tot].nex=head[u];
	e[tot].w=w;
	head[u]=tot;
}
int n,m,root,sum=0;//重心,sum当前大小
int siz[maxn],maxp[maxn];
bool vis[maxn];
void getrt(int x,int fa)
{//DFS找重心
	siz[x]=1,maxp[x]=0;//maxp为最大子树大小
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa||vis[v])
			continue;
		getrt(v,x);
		siz[x]+=siz[v];
		if(siz[v]>maxp[x])
			maxp[x]=siz[v];//记录下面的最大子树大小
	}//无根树,sum-siz[x]为以x的父节点为根的大小
	//在以自身为根节点的子树大小和以x的父节点为根的大小中取较大的
	maxp[x]=max(maxp[x],sum-siz[x]);//sum为整棵树的大小
	if(maxp[x]<maxp[root])
		root=x;//最大子树最小的点为重心
}
int dist[maxn],tmp[maxn],cnt=0;//cnt计数器
void getdist(int x,int fa)
{//DFS求各点到root的距离,记录在tmp中
	tmp[++cnt]=dist[x];
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa||vis[v])
			continue;
		dist[v]=dist[x]+e[i].w;
		getdist(v,x);
	}
}
int q[105];//q记录询问距离
bool jud[maxk],ans[105];//存放之前子树中的存在路径长度,ans判断k是否存在
queue<int> QwQ;
void solve(int x)
{//处理经过根节点x的路径
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(vis[v])//该点已经被去掉
			continue;
		cnt=0;
		dist[v]=e[i].w;//设置root与儿子的距离
		getdist(v,x);
		for(int j=1;j<=cnt;j++)//遍历该子树上的距离
			for(int k=1;k<=m;k++)//遍历询问
				if(q[k]>=tmp[j])//有拼出来的可能性
					ans[k]|=jud[q[k]-tmp[j]];//可以用之前以x为顶的距离拼起来
		for(int j=1;j<=cnt;j++)//将这棵子树的距离存起来
		{//供之后的以x为节点的子树拼路径使用
			QwQ.push(tmp[j]);
			jud[tmp[j]]=1;
		}
	}
	while(!QwQ.empty())
	{
		jud[QwQ.front()]=0;
		QwQ.pop();
	}
}
void divide(int x)
{
	vis[x]=jud[0]=1;//去掉根节点x
	solve(x);//处理所有经过x的路径
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(vis[v])
			continue;
		maxp[root=0]=sum=siz[v];//重心置为0,maxp[0]置为最大值(所以要重新DFS计算siz)
		getrt(v,0);//在以v为根的子树上找重心
		getrt(root,0);//处理出以v为根的siz数组
		divide(root);
	}
}
int main()
{
	int k,u,v;
	ll w;
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=m;i++)
		cin>>q[i];
	maxp[0]=sum=n;//置为最大值
	getrt(1,0);
	getrt(root,0);//更新以重心为根的siz数组
	divide(root);
	for(int i=1;i<=m;i++)
		cout<<(ans[i]?"AYE":"NAY")<<'\n';
	return 0;
}
