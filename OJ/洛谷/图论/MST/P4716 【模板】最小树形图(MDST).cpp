#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005,inf=0x3f3f3f3f;
struct edge
{
	int u,v,w;
	edge(int u,int v,int w):
		u(u),v(v),w(w){}
};
vector<edge> G;//该算法会修改边
int id[maxn],in[maxn],pre[maxn],vis[maxn];//in[x]表示x入边最小权,pre[x]表示x最小入边的出点
ll zltree(int root,int n)//id[x]为x节点在G图上的编号
{
	ll ans=0;
	while(1)
	{
		fill(in,in+n+1,inf);
		for(auto &e:G)
			if(e.u!=e.v&&e.w<in[e.v])
			{
				pre[e.v]=e.u;//记录最小入边出点
				in[e.v]=e.w;//记录最小入边权
			}
		for(int i=1;i<=n;i++)
			if(i!=root&&in[i]==inf)
				return -1;//存在非根点没有入边,无MDST
		fill(id,id+n+1,0);
		memset(vis,0,sizeof(vis));
		int tn=0,v;//tn记录环的数量
		in[root]=0;//根节点无入边,权为0(这样不用特判)
		for(int i=1;i<=n;i++)//找环
		{
			ans+=in[v=i];//加v入边贡献
			while(vis[v]!=i&&!id[v]&&v!=root)//
				vis[v]=i,v=pre[v];//检查v的最小入边出点,并标记vis为i
			if(v!=root&&!id[v])
			{
				id[v]=++tn;//标记环的编号
				for(int u=pre[v];u!=v;u=pre[u])
					id[u]=tn;//将v所在环打上同一个标记
			}
		}
		if(tn==0)//无环
			break;
		for(int i=1;i<=n;i++)
			if(!id[i])//给不在环上的点新编号
				id[i]=++tn;
		for(int i=0;i<(int)G.size();)//更新为新图G1
		{
			auto &e=G[i];
			v=e.v;
			e.u=id[e.u],e.v=id[e.v];
			if(e.u!=e.v)//更新指向环的边权
				e.w-=in[v],i++;
			else
			{
				swap(e,G.back());
				G.pop_back();
			}
		}
		n=tn;//更新新图的点数
		root=id[root];//更新新图上根节点编号
	}
	return ans;
}
int main()
{
	int n,m,r,u,v,w;
	cin>>n>>m>>r;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		G.push_back(edge(u,v,w));//有向
	}
	cout<<zltree(r,n)<<endl;
	return 0;
}
