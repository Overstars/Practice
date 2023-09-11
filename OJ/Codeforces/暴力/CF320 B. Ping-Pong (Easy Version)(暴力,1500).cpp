#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
struct node
{
	int a,b;
} arr[maxn];
int cnt=0,fa[maxn];
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
void Insert(int x,int y)
{//似乎是单向的,不能用并查集...
	arr[++cnt].a=x;
	arr[cnt].b=y;
//	fa[cnt]=cnt;
//	for(int i=1;i<cnt;i++)
//	{
//		if(arr[cnt].a<arr[i].a&&arr[i].a<arr[cnt].b)
//			Merge(i,cnt);
//		else if(arr[cnt].a<arr[i].b&&arr[i].b<arr[cnt].b)
//			Merge(i,cnt);
//	}
}
bool query(int x,int y)
{
	if(findfa(x)==findfa(y))
		return 1;
	return 0;
}
bool vis[maxn];
void dfs(int x,int tar)
{
	vis[x]=1;
	if(vis[tar])
		return;
	for(int i=1;i<=cnt;i++)
	{
		if(vis[i])
			continue;
		if(arr[i].a<arr[x].a&&arr[x].a<arr[i].b)
			dfs(i,tar);
		else if(arr[i].a<arr[x].b&&arr[x].b<arr[i].b)
			dfs(i,tar);
	}
}
int main()
{
	int q,ope,x,y;
	cin>>q;
	while(q--)
	{
		cin>>ope>>x>>y;
		if(ope==1)
		{
			Insert(x,y);
		}
		else{
			memset(vis,0,sizeof(vis));
			dfs(x,y);
			if(vis[y])
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}
