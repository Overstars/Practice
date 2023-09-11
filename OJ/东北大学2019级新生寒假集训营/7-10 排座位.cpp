#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int mp[maxn][maxn],fa[maxn];
int findfa(int x)
{
	if(x!=fa[x])
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(b<a)
		fa[a]=b;
	else
		fa[b]=a;
	return 1;
}
int main()
{
	int n,m,k,u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		if(w==-1)
			mp[u][v]=mp[v][u]=1;//标记为直接敌人
		else if(w==1)
			Merge(u,v);
	}
	while(k--)
	{
		cin>>u>>v;
		int a=findfa(u),b=findfa(v);
		if(a==b)
		{
			if(mp[u][v])
				cout<<"OK but...\n";
			else
				cout<<"No problem\n";
		}
		else{
			if(mp[u][v])
				cout<<"No way\n";
			else
				cout<<"OK\n";
		}
	}
	return 0;
}
