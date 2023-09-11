#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>G[maxn],ans1,ans2;
int c1=0,c2=0;
int col[maxn];
bool dfs(int x,int color)//黑白染色
{
	if(col[x])
	{
		if(col[x]==color)
			return 0;
		else
			return 1;
	}
	col[x]=color;
	if(color==1)
	{
		c1++;
		ans1.push_back(x);
	}
	else{
		c2++;
		ans2.push_back(x);
	}
	for(auto &v:G[x])
	{
		if(dfs(v,(color==1)?2:1))
			return 1;
	}
	return 0;
}
int main()
{
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!col[i]&&dfs(i,1))//可能不是连通图
		{
			cout<<-1<<endl;
			exit(0);
		}
	}
	cout<<c1<<endl;
	for(auto &i:ans1)
		cout<<i<<' ';
	cout<<'\n'<<c2<<endl;
	for(auto &i:ans2)
		cout<<i<<' ';
	return 0;
}
/*
 *题意:无向图的节点分为两份,每一份都是原图的点覆盖
 *神奇的SPJ...
 *孤立点随便分到一边就好,不会影响覆盖
 */

