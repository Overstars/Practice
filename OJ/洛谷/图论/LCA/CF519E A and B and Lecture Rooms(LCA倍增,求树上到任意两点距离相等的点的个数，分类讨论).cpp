#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=100005;
const int maxl=30;
vector<int> G[maxn];
int gene[maxn][maxl],depth[maxn],lg[maxn];
int nodes[maxn];//子树结点的数量
void dfs(int x,int fa)
{
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
	nodes[x]=1;
	for(int i=1;(1<<i)<=depth[x];i++)
		gene[x][i]=gene[gene[x][i-1]][i-1];
	for(int i=0;i<G[x].size();i++)
		if(G[x][i]!=fa)
		{
			dfs(G[x][i],x);
			nodes[x]+=nodes[G[x][i]];
		}
}
int lca(int x,int y)
{
	if(depth[x]<depth[y])
		swap(x,y);
	while(depth[x]>depth[y])
		x=gene[x][lg[depth[x]-depth[y]-1]];
	if(x==y)
		return x;
	for(int i=lg[depth[x]];i>=0;i--)
		if(gene[x][i]!=gene[y][i])
		{
			x=gene[x][i];
			y=gene[y][i];
		}
	return gene[x][0];
}
int dist(int x,int y)
{
	int tem=lca(x,y);
	return (int)(abs(depth[x]-depth[tem])+abs(depth[y]-depth[tem]));
}
int findmid(int x,int len)//从x节点向上len步
{
	int ans=x;
	for(int i=lg[len]+1;i>=0;i--)
		if(depth[x]-depth[gene[ans][i]]<=len)
			ans=gene[ans][i];
	return ans;
}
void init(int s)
{
	memset(nodes,0,sizeof(nodes));
	memset(gene,0,sizeof(gene));
	depth[s]=1;
	dfs(s,0);
}
int main()
{
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	init(1);
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x==y)
		{
			cout<<n<<endl;
			continue;
		}
		int a=lca(x,y);//x,y的LCA
		int dis=dist(x,y);
		if(dis&1)//路径上距离为奇数
		{
			cout<<0<<endl;
		}
		else{
			int mid;//中点
			if(depth[x]>depth[y])//mid在x这一侧找
			{
				mid=findmid(x,dis/2);
				cout<<nodes[mid]-nodes[findmid(x,dis/2-1)]<<endl;
			}
			else if(depth[x]<depth[y])//mid在y上面找
			{
				mid=findmid(y,dis/2);
				cout<<nodes[mid]-nodes[findmid(y,dis/2-1)]<<endl;
			}
			else{
				cout<<n-nodes[findmid(x,dis/2-1)]-nodes[findmid(y,dis/2-1)]<<endl;//n去掉lca下面的连接x与y的子树的节点数
			}
		}
	}
	return 0;
}
