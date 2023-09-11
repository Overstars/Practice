#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f,MAXN=125;
struct edge
{
	int u,v,w;
} e[MAXN*MAXN];
int father[MAXN];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int findfa(int x)
{
	if(x!=father[x])
		father[x]=findfa(father[x]);
	return father[x];
}
int Merge(int a,int b)
{
	int x=findfa(a),y=findfa(b);
	if(x==y)
		return 0;
	if(x>y)
		father[x]=y;
	else
		father[y]=x;
	return 1;
}
int kruskal(int n,int m)
{
	int ans=0;
	for(int i=0;i<m;i++)
	{
		if(Merge(e[i].u,e[i].v))
		{
			ans+=e[i].w;
			n--;
			if(n==1)
				return ans;
		}
	}
	return 0;
}
int main()
{
	int n,m,i,j,x,y,w;
	while(cin>>n&&n)
	{
		for(i=1;i<=n;i++)
			father[i]=i;
		int m=n*(n-1)/2;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		}
		sort(e,e+m,cmp);
		cout<<kruskal(n,m)<<endl;
	}
	return 0;
}
