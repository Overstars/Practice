#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int fa[maxn],siz[maxn];
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
	if(a<b)
	{
		fa[b]=a;
		siz[a]+=siz[b];
		siz[b]=0;
	}
	else{
		fa[a]=b;
		siz[b]+=siz[a];
		siz[a]=0;
	}
	return 1;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int k,m1,m2;
		cin>>k;
		if(k-->0)
			cin>>m1;
		while(k-->0)
		{
			cin>>m2;
			Merge(m1,m2);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<siz[findfa(i)]<<' ';
	return 0;
}
