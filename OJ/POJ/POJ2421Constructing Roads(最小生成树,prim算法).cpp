#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>//在已经建好一些道路的村庄再建最短距离的道路,使各村庄连接
using namespace std;
const int inf=0x3f3f3f3f,maxn=105;
int dist[maxn][maxn],closest[maxn],lowcost[maxn];
bool tree[maxn];
int prim(int n,int u0)
{
	memset(tree,0,sizeof(tree));
	tree[u0]=1;
	int i,j;
	for(i=1;i<=n;i++)
		if(i!=u0){
			lowcost[i]=dist[u0][i];
			closest[i]=i;
		}
		else
			lowcost[u0]=0;
	for(i=1;i<=n;i++)
	{
		int temp=inf,t;
		for(j=1;j<=n;j++)
		{
			if(!tree[j]&&lowcost[j]<temp)
			{
				t=j;
				temp=lowcost[j];
			}
		}
		if(t==u0)
			break;
		tree[t]=1;
		for(j=1;j<=n;j++)
		{
			if(!tree[j]&&dist[t][j]<lowcost[j])
			{
				lowcost[j]=dist[t][j];
				closest[j]=t;
			}
		}
	}
	int ans=0;
	for(i=1;i<=n;i++)
		ans+=lowcost[i];
	return ans;
}
int main()
{
	int n,q,x,y;
	cin>>n;
	memset(dist,inf,sizeof(dist));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&dist[i][j]);
	cin>>q;
	while(q--){
		scanf("%d%d",&x,&y);
		dist[x][y]=dist[y][x]=0;//已经联通
	}
	printf("%d\n",prim(n,1));
	return 0;
}
