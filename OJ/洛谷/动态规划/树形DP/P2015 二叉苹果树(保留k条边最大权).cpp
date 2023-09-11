#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
struct edge
{
	int v,w;
	edge(int v=0,int w=0):
		v(v),w(w){}
};
vector<edge> G[maxn];
int dp[maxn][maxn],siz[maxn],q;//dp[i][j]以i为根的树上保留j条边
void dfs(int x,int fa)
{
	siz[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		int v=G[x][i].v;
		if(v==fa)
			continue;
		dfs(v,x);
		siz[x]+=siz[v];//x节点数,节点有siz-1条边
		for(int j=min(siz[x],q);j>0;j--)//树上三维背包降维
		{//枚举x根树上之前保留边数
			for(int k=min(siz[v],j-1);k>=0;k--)//枚举新加入的v子树加入的边
			{
				dp[x][j]=max(dp[x][j],dp[x][j-k-1]+dp[v][k]+G[x][i].w);//保留(x,v)边以及v树上的k条边
			}//dp[v][k]以v为节点保留k条边
		}
	}
}
int main()//dp[i][j]表示顶点i保留j条边的权值
{
	int n;//节点数,保留树枝数量
	cin>>n>>q;
	for(int i=1;i<n;i++)//n-1条数枝
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(edge(v,w));
		G[v].push_back(edge(u,w));
	}
	dfs(1,0);
	cout<<dp[1][q]<<endl;
	return 0;
}
