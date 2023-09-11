#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char grid[10][10],flag[10][10];
int n,m,t,away=0,a,b;//a,b为终点
void dfs(int r,int c,int cnt);
int main()
{
	int i,j,x,y;//从S走T步到D
	while(cin>>n>>m>>t&&(n||m||t)){
		away=0;
		memset(flag,0,sizeof(flag));
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				scanf(" %c",&grid[i][j]);
				if(grid[i][j]=='S'){
					x=i;
					y=j;
				}
				else if(grid[i][j]=='D'){
					a=i;
					b=j;
				}
			}
		dfs(x,y,0);
		if(n*m>=t&&away)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
void dfs(int r,int c,int cnt)
{
	if(r>=n||c>=m||r<0||c<0)//超出范围
		return;
	if(cnt==t&&grid[r][c]=='D'){
		away=1;
		return;
	}
	if(away||cnt>=t||(t-cnt-abs(r-a)-abs(c-b))%2==1)//有一个成功方案，全部结束。超时,剪枝。
		return;//奇偶剪枝,剩余时间与对目前为止来说的最短时间之差为奇数,则不可能恰好达到
	flag[r][c]=1;
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++){
			if(i!=j&&!flag[r+i][c+j]&&grid[r+i][c+j]!='X')
				dfs(r+i,c+j,cnt+1);//向4个方向搜索未搜索的且可以走的
		}
	flag[r][c]=0;
}
