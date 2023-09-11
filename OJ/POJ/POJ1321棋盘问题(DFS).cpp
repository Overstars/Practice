#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char grid[10][10];
int n,k,vis[10],cnt;//该列是否占用
void dfs(int floor,int x,int y)
{
	if(floor==k){
		cnt++;
		return;
	}
	for(int i=x+1;i<n;i++)//从下一行开始
		for(int j=0;j<n;j++){
			if(grid[i][j]=='#'&&!vis[j]){
				vis[j]=1;
				dfs(floor+1,i,j);
				vis[j]=0;
			}
		}
}
int main()
{
	int i,j;
	while(cin>>n>>k&&n!=-1&&k!=-1){//摆放k个棋子
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf(" %c",&grid[i][j]);
		cnt=0;
		dfs(0,-1,0);
		cout<<cnt<<endl;
	}
	return 0;
}
