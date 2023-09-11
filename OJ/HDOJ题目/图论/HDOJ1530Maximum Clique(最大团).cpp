#include<bits/stdc++.h>
using namespace std;
const int maxn=60;
int G[maxn][maxn],tmp[maxn][maxn];//tmp[i][j]搜到第i层
int n,ans,tot,f[maxn];//Bron-Kerbosch 算法,复杂度3^n
stack<int>stk,rec;
bool dfs(int dep,int num)//深度(团大小),备选集合大小num
{//当前层数dep,num表示与当前层相邻的比
	if(num==0)
	{
		if(dep>ans)
		{
			ans=dep;
			rec=stk;
			return 1;
		}
		return 0;
	}
	for(int i=1;i<=num;i++)
	{
		if(dep+num-i+1<=ans)//剪枝1,不会超过当前最优解
			return 0;
		int v=tmp[dep][i];
		if(dep+f[v]<=ans)//剪枝f[v]+已经取了的点仍不超过最优解
			return 0;
		int cnt=0;
		for(int j=i+1;j<=num;j++)
		{
			int vv=tmp[dep][j];
			if(G[v][vv])
				tmp[dep+1][++cnt]=vv;
		}
		stk.push(v);
		if(dfs(dep+1,cnt))
			return 1;
	}
	return 0;
}
int maxClique(int n)
{
	if(n==0)
		return 0;
	memset(f,0,sizeof(f));
	f[n]=ans=1;
	for(int i=n-1;i>=1;i--)
	{
		tot=0;//以i为最小编号点的最大团
		while(!stk.empty())
			stk.pop();
		stk.push(i);
		for(int j=i+1;j<=n;j++)
			if(G[i][j])
				tmp[1][++tot]=j;
		dfs(1,tot);
		f[i]=ans;
	}
	return ans;
}
int main()
{//回溯法求最大团
	while(cin>>n&&n)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>G[i][j];
		cout<<maxClique(n)<<endl;
//		while(!rec.empty())
//		{
//			cout<<rec.top()<<endl;
//			rec.pop();
//		}
	}
	return 0;
}

