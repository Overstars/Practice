#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 1030;
int G[maxn][maxn];
int deg[maxn];//CSL板子这里改一下
vector<int> ans;
inline void init()
{
	memset(G, 0, sizeof(G));
	memset(deg, 0, sizeof(deg));
}
inline void AddEdge(int u, int v)
{
	deg[u]++, deg[v]++, G[u][v]++, G[v][u]++;
}
void Fleury(int s,int n)
{
	for (int i = 1; i <= n; i++)
		if (G[s][i])
		{
			G[s][i]--, G[i][s]--;
			Fleury(i,n);
		}
	ans.push_back(s);
}
int main()
{
	int f,u,v,M=0;
	cin>>f;
	for(int i=0;i<f;i++)
	{
		cin>>u>>v;
		M=max(M,u);
		M=max(M,v);
		AddEdge(u,v);
	}
	int st=1;
	for(int i=1;i<=M;i++)
		if(deg[i]&1)
		{
			st=i;
			break;//找到最小奇点
		}
	Fleury(st,M);//开始搜索
	for(int i=ans.size()-1;i>=0;i--)//要求倒序输出
		printf("%d\n",ans[i]);
	return 0;
}
