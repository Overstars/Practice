#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=505,inf=0x3f3f3f3f,mod=1000000007;
int fa[maxn];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
		fa[b]=a;
	else
		fa[a]=b;
	return 1;
}
struct edge
{
	int u,v,w;
	edge(int u,int v,int w):
		u(u),v(v),w(w){}
};
int mp[maxn][maxn];
bool cmp(const edge &a,const edge &b)
{
		return a.w<b.w;
}
int sol(int n)
{
	vector<edge>G;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			G.push_back(edge(i,j,mp[i][j]));
	sort(G.begin(),G.end(),cmp);
	for(int i=0;i<G.size();i++)
	{
		edge &e=G[i];
		if(Merge(e.u,e.v))
		{
			n--;
			if(n==1)
				return e.w;
		}
	}
	return 0;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&mp[i][j]);
		printf("%d\n",sol(n));
	}
	return 0;
}


