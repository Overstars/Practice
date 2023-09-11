#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
char grid[10][10],flag[10][10];
int n,m,t,away=0,a,b;//a,bΪ�յ�
void dfs(int r,int c,int cnt);
int main()
{
	int i,j,x,y;//��S��T����D
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
	if(r>=n||c>=m||r<0||c<0)//������Χ
		return;
	if(cnt==t&&grid[r][c]=='D'){
		away=1;
		return;
	}
	if(away||cnt>=t||(t-cnt-abs(r-a)-abs(c-b))%2==1)//��һ���ɹ�������ȫ����������ʱ,��֦��
		return;//��ż��֦,ʣ��ʱ�����ĿǰΪֹ��˵�����ʱ��֮��Ϊ����,�򲻿���ǡ�ôﵽ
	flag[r][c]=1;
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++){
			if(i!=j&&!flag[r+i][c+j]&&grid[r+i][c+j]!='X')
				dfs(r+i,c+j,cnt+1);//��4����������δ�������ҿ����ߵ�
		}
	flag[r][c]=0;
}
