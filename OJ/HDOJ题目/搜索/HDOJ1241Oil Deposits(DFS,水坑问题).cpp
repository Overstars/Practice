#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char grid[105][105];
int flag[105][105];
int m,n,cnt;
void dfs(int r,int c);
int main()
{
	while(cin>>m>>n&&m){
		cnt=0;
		memset(flag,0,sizeof(flag));
		int i,j;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++){
				scanf(" %c",&grid[i][j]);
			}
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				if(grid[i][j]=='@'&&!flag[i][j]){
					dfs(i,j);
					cnt++;
				}
		cout<<cnt<<endl;
	}
	return 0;
}
void dfs(int r,int c)
{
	if(r>m||c>n||r<=0||c<=0)//边界
		return;
	if(grid[r][c]=='@'&&!flag[r][c]){
		flag[r][c]=1;
		for(int i=-1;i<=1;i++)
			for(int j=-1;j<=1;j++){
				if(!(i==0&&j==0)&&!flag[r+i][c+j])
					dfs(r+i,c+j);//向八个方向搜索,直至所有相邻@被标记
		}
	}
}
