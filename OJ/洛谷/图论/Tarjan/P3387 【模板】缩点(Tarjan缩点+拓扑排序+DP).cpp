#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
int tot=0,Index=0,cnt=0;
int stk[maxn],dfn[maxn],low[maxn],belong[maxn];
int val[maxn],rec[maxn];//每个强连通分量的值
bool vis[maxn];
vector<int> G[maxn];
void tarjan(int x)
{
	dfn[x]=low[x]=++tot;
	stk[++Index]=x;
	vis[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		if(!dfn[G[x][i]])
		{
			tarjan(G[x][i]);
			low[x]=min(low[x],low[G[x][i]]);
		}
		else if(vis[G[x][i]])
			low[x]=min(low[x],dfn[G[x][i]]);
	}
	if(low[x]==dfn[x])
	{
//		int tem=0;
		cnt++;
		do{
			belong[stk[Index]]=cnt;
			rec[cnt]+=val[stk[Index]];
			vis[stk[Index]]=0;
			Index--;
		}while(stk[Index+1]!=x);
	}
}
vector<int> Gra[maxn];
int dp[maxn],top[maxn],into[maxn];
int topsort(void)
{
	queue<int> QAQ;
	for(int i=1;i<=cnt;i++)
	{
		if(!into[i])
			QAQ.push(i);
		dp[i]=rec[i];
	}
	int flag=0;
	while(!QAQ.empty())
	{
		int x=QAQ.front();
		QAQ.pop();
		top[x]=++flag;
		for(int i=0;i<Gra[x].size();i++)
		{
			dp[Gra[x][i]]=max(dp[Gra[x][i]],dp[x]+rec[Gra[x][i]]);
			if(--into[Gra[x][i]]==0)
				QAQ.push(Gra[x][i]);
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;i++)
		ans=max(ans,dp[i]);
	return ans;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>val[i];//每个点的值
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
	}
	for(int i=1;i<=n;i++)//Tarjan缩点部分
		if(!dfn[i])
			tarjan(i);//缩点
	for(int i=1;i<=m;i++)//拓扑排序部分
		for(int j=0;j<G[i].size();j++)
		{
			int x=belong[i],y=belong[G[i][j]];
			if(x!=y)
			{
				Gra[x].push_back(y);//建立新图DAG
				into[y]++;
			}
		}
	cout<<topsort()<<endl;
	return 0;
}
