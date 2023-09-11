#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100005;
struct edge
{
	int u,v,w;
} e[maxn];
int fa[maxn];
bool cmp(const edge &a,const edge &b)
{
	return a.w>b.w;//这里要找最大生成树
}
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int a,int b)
{
	int p=findfa(a),q=findfa(b);
	if(p==q)
		return 0;
	if(p<q)
		fa[q]=p;
	else
		fa[p]=q;
	return 1;
}
int kruskal(int n,int m,int k)
{
	int ans=0;
	for(int i=0;i<m;i++)
	{
		if(Merge(e[i].u,e[i].v))
		{
			ans+=e[i].w;
			n--;
			k--;
			if(n==1||k==0)
				return ans;
		}
	}
	return 0;
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++)
		fa[i]=i;
	for(int i=0;i<m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e,e+m,cmp);
	cout<<kruskal(n,m,k)<<endl;;
	return 0;
}
