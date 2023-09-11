#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char matrix[105][105];
int step[105][105],ynext[4]={-1,0,1,0},xnext[4]={0,-1,0,1},m,n,x1,yy1,x2,y2,k,flag;
const int INF=0x3f3f3f3f;
void dfs(int y,int x,int dir);
int main()
{
	int t,i,j;
	cin>>t;
	while(t--){
		scanf("%d %d",&m,&n);
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++){
				scanf(" %c",&matrix[i][j]);
			}
		scanf("%d %d %d %d %d",&k,&x1,&yy1,&x2,&y2);
		flag=0;
		memset(step,INF,sizeof(step));
		step[yy1][x1]=0;
		dfs(yy1,x1,-1);
		if(flag)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
void dfs(int y,int x,int dir)
{
	if(x==x2&&y==y2){//�ﵽ
		if(step[y][x]<=k)
			flag=1;
		return;
	}
	if(flag)
		return;
	if(x!=x2&&y!=y2&&k<=step[y][x]||step[y][x]>k)
		return;
	for(int i=0;i<4;i++){//�������ĸ���������
		int ty=y+ynext[i];
		int tx=x+xnext[i];
		if(matrix[ty][tx]=='*'||step[ty][tx]<step[y][x])//ǽ||֮ǰ�ѹ�
			continue;
		if(dir!=-1&&i!=dir&&step[ty][tx]<=step[y][x])//��һ������ͬ,��¼��ת�����ȴ�ȵ�ǰ��
			continue;
		if(tx<=0||tx>n||ty<=0||ty>m)//Խ��
			continue;
		if(dir!=-1&&i!=dir)//����ı�
			step[ty][tx]=step[y][x]+1;
		else
			step[ty][tx]=step[y][x];
		dfs(ty,tx,i);
	}
}
