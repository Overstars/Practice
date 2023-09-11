#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int father[maxn];
struct edge
{
	int u,v,w;
	edge(int u=0,int v=0,int w=0):
		u(u),v(v),w(w){}
	bool operator <(const edge&a)const
	{
		return w<a.w;
	}
} a[maxn*maxn];
int findfa(int x)
{
	if(father[x]!=x)
		father[x]=findfa(father[x]);
	return father[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
		father[b]=a;
	else
		father[a]=b;
	return 1;
}
int kruskal(int n,int m)
{
	sort(a,a+m);
	for(int i=1;i<=n;i++)
		father[i]=i;
	int ans=0;
	for(int i=0;i<m;i++)
	{
		if(Merge(a[i].u,a[i].v))
		{
			ans+=a[i].w;
			n--;
			if(n==1)
				return ans;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,tem,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>tem;
		a[cnt++]=edge(n+1,i,tem);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>tem;
			a[cnt++]=edge(i,j,tem);
		}
	}
	cout<<kruskal(n+1,cnt)<<endl;
	return 0;
}
