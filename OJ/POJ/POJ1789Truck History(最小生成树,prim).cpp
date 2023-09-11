#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f,maxn=2005;
char str[maxn][10];
int dist[maxn][maxn],closest[maxn],lowcost[maxn];
bool tree[maxn];
int prim(int n,int u0)
{
	memset(tree,0,sizeof(tree));
	tree[u0]=1;
	int i,j,ans=0;
	for(i=1;i<=n;i++)
		if(i!=u0)
		{
			closest[i]=i;
			lowcost[i]=dist[u0][i];
		}
		else
			lowcost[i]=0;
	for(i=1;i<=n;i++)
	{
		int temp=inf,t=u0;
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
		ans+=lowcost[t];
		for(j=1;j<=n;j++)
		{
			if(!tree[j]&&dist[t][j]<lowcost[j])
			{
				closest[j]=t;
				lowcost[j]=dist[t][j];
			}
		}
	}
	return ans;
}
int main()
{
	int n,i,j,k;
	while(cin>>n&&n)//没判断n==0就WA了...
	{
		for(i=1;i<=n;i++)
			scanf("%s",str[i]);
		memset(dist,inf,sizeof(dist));
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
			{
				int cnt=0;
				for(k=0;k<7;k++)//字符串只有七个字符
					if(str[i][k]!=str[j][k])
						cnt++;
				dist[i][j]=dist[j][i]=cnt;
			}
		printf("The highest possible quality is 1/%d.\n",prim(n,1));
	}
	return 0;
}
