#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,grid[105][105],dp[105][105];//dp[i][j]表示从该点出发得到的最大点数
int nx[4]={-1,0,1,0},ny[4]={0,1,0,-1};
int dfs(int x,int y)
{
	if(dp[x][y])//搜过该点
		return dp[x][y];
	int tx,ty,ans=0;
	for(int i=0;i<4;i++){
		for(int j=1;j<=k;j++){//列举求为出dp[x][y]的所有前置状态
			tx=x+nx[i]*j;
			ty=y+ny[i]*j;
			if(tx<0||tx>=n||ty<0||ty>=n||grid[tx][ty]<=grid[x][y])
				continue;
			ans=max(ans,dfs(tx,ty));
		}
	}
	return dp[x][y]=ans+grid[x][y];
}
int main()
{
	while(cin>>n>>k&&n!=-1&&k!=-1){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&grid[i][j]);
		memset(dp,0,sizeof(dp));
		cout<<dfs(0,0)<<endl;
	}
	return 0;
}
