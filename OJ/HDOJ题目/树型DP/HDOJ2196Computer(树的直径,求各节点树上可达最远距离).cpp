#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct edge
{
	int v,w,nex;
}  e[maxn<<1];
int head[maxn],cnt;
inline void add(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].nex=head[u];
	e[cnt].w=w;
	head[u]=cnt;
}
int root,depth[maxn],height[maxn],ans[maxn];
void dfs(int x,int fa)
{
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa)
			continue;
		depth[v]=depth[x]+e[i].w;
		height[v]=0;
		dfs(v,x);
		height[x]=max(height[x],height[v]+e[i].w);
	}
	ans[x]=max(ans[x],max(height[x],depth[x]));
	if(depth[x]>depth[root])
		root=x;
}
signed main()
{
//	freopen("HDOJ2196.in","r",stdin);
	int n;
	while(~scanf("%d",&n))
	{
		int v,w;
		memset(depth,0,sizeof(depth));
		memset(height,0,sizeof(height));
		memset(ans,0,sizeof(ans));
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=2;i<=n;i++)
		{
			scanf("%d%d",&v,&w);
			add(v,i,w);
			add(i,v,w);
		}
		dfs(1,0);//找出树直径的一端
		memset(depth,0,sizeof(depth));
		memset(height,0,sizeof(height));
//		printf("root=%d\n",root);
//		height[root]=0;
		dfs(root,0);//以root为根求出深度和高度
//		printf("root=%d\n",root);
		memset(height,0,sizeof(height));
		memset(depth,0,sizeof(depth));
		dfs(root,0);//从直径另一端开始深搜
		for(int i=1;i<=n;i++)
		{
			printf("%d\n",ans[i]);
//			printf("h[%d]=%d,d[%d]=%d\n",i,height[i],i,depth[i]);
		}
	}
	return 0;
}
/*
test1.卡掉两遍DFS
5
1 2
2 3
2 2
1 4
ans
5
6
9
8
9
 */

