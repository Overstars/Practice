#include<bits/stdc++.h>
using namespace std;
const int maxn=50;
int fa[maxn],siz[maxn];
vector<int>ans[maxn];
bool vis[maxn];
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
		ans[a].insert(ans[a].end(),ans[b].begin(),ans[b].end());
	}
	else{
		fa[a]=b;
		siz[b]+=siz[a];
		ans[b].insert(ans[b].end(),ans[a].begin(),ans[a].end());
	}
	return 1;
}
int main()
{
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		siz[i]=1;
		ans[i].push_back(i);
	}
	while(m--)
	{
		cin>>u>>v;
		Merge(u,v);
	}
	int c1=0,c2=0;
	for(int i=1;i<=n;i++)
	{
		int now=findfa(i);
		if(vis[now])
			continue;
		vis[now]=1;
		if(siz[now]>3)
		{
			cout<<"-1\n";
			exit(0);
		}
		else if(siz[now]==1)
			c1++;
		else if(siz[now]==2)
			c2++;
	}
	if(c1<c2||(c1-c2)%3!=0)
	{
		cout<<"-1\n";
		exit(0);
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		int now=findfa(i);
		if(vis[now])
			continue;
		vis[now]=1;
		while(siz[now]<3)
		{//因为往小合并,祖宗肯定是now
//			printf("HAY!\n");
			for(int j=i+1;j<=n;j++)
			{
				int another=findfa(j);
				if(vis[another]||(siz[now]==1&&c2>0&&siz[another]==1))
				{//1优先与2合并
//					printf("HA?\n");
					continue;
				}
				if(siz[now]+siz[another]<=3)
				{
					if(siz[now]+siz[another]==3)
						c2--;
					Merge(now,another);
					if(siz[now]==3)
						break;
				}
			}
		}
		for(auto &j:ans[now])
			cout<<j<<' ';
		cout<<'\n';
	}
	return 0;
}
