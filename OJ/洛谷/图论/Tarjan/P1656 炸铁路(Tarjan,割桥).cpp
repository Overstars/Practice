#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=20005;
struct edge
{
	int v, no;
	edge(int v,int no):
		v(v),no(no){}
};
vector<edge> G[maxn];
int dfn[maxn],low[maxn],tot,cnt=0,flag=0;
bool bri[maxn];
pair<int,int> ans[maxn];
bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.first<b.first)
		return 1;
	if(a.first==b.first)
		return a.second<b.second;
	return 0;
}
bool stcmp(const edge &a,const edge &b)
{
	return a.v<b.v;
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++tot;
	bool vis=0;//处理重边要加上,表示这个节点还没有被子树搜到
	for(int i=0;i<G[x].size();i++)
	{
		int v=G[x][i].v,no=G[x][i].no;
		if(!dfn[v])
		{
			tarjan(v,x);
			if(low[v]>dfn[x])//讨论桥是大于
			{
				bri[no]=1;
//				pair<int,int> tem;
//				tem.first=x,tem.second=v;
//				ans[flag++]=tem;
			}
			low[x]=min(low[x],low[v]);
		}
		else if(dfn[x]>dfn[v])
		{
			if(v==fa&&!vis)
				vis=1;//除了第一次，每次回到父节点都用父节点的值更新当前结点的值
			else//之前是v!=fa时才用父节点值更新该点的值
				low[x]=min(low[x],dfn[v]);
		}
	}
}
//#define DEBUG
int main()
{
	#ifdef DEBUG
	freopen("P1656.in","r",stdin);
	#endif // DEBUG
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(edge(v,++cnt));//无向图
		G[v].push_back(edge(u,++cnt));
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i,i);
	for(int i=1;i<=n;i++)//边的起点有序
	{
		sort(G[i].begin(),G[i].end(),stcmp);
		for(int j=0;j<G[i].size();j++)//要先对每一个vector排序再输出
			if(bri[G[i][j].no])
				cout<<i<<' '<<G[i][j].v<<endl;
	}
//	sort(ans,ans+flag,cmp);
//	for(int i=0;i<flag;i++)
//		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}
/*
int n,m,x,y,index_,dfn[maxn],low[maxn],ans,a;//index_代表当前的时间戳
vector<int>G[maxn];//存边的数据结构：邻接表
struct Edge{int from,to;}edge[maxn];//答案的边，最后需要排序
bool cmp(const Edge a,const Edge b){if(a.from!=b.from)return a.from<b.from;return a.to<b.to;}//答案边的比较函数
inline void add_edge(int x,int y){edge[ans].from=min(x,y);edge[ans].to=max(x,y);ans++;}//在答案中加入一条边
void dfs(int cur,int fa)//cur是当前节点，fa是他的父亲
{
    int child;
    dfn[cur]=++index_;//计算当前节点的时间戳
    low[cur]=dfn[cur];//当前可以访问到的最早时间戳肯定是自己的时间戳
    for(int i=0;i<G[cur].size();i++)//遍历cur的所有出点
    {
        child=G[cur][i];
        if(dfn[child]&&child!=fa)
			low[cur]=min(low[cur],dfn[child]);//如果访问到了不是父亲节点的节点，更新low的值
        if(!dfn[child])//如果这个节点之前没有被访问过
        {
            dfs(child,cur);//进行一次dfs过程
            if(dfn[cur]<low[child])add_edge(cur,child);//如果满足条件，在答案序列中加入这条边
            low[cur]=min(low[cur],low[child]);//更新low的值
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)scanf("%d%d",&x,&y),G[x].push_back(y),G[y].push_back(x);
    for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,i);//图可能不连通，初始时fa是i不会出现问题
    sort(edge,edge+ans,cmp);//将答案序列排个序
    for(int i=0;i<ans;i++)printf("%d %d\n",edge[i].from,edge[i].to);//输出
    return 0;
}
*/
