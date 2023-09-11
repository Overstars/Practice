#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;//���R��A�����ʱ��,��ÿ��r��ʼ�������ӶȻ�ܸ�?
char matrix[205][205];//������������a��r��ʱ����Сֵ����
int n,m,flag[205][205],mini;
const int INF=0x3f3f3f3f;
void dfs(int x,int y,int cnt);
int main()
{
	int i,j,ax,ay;
	while(cin>>n>>m){
		mini=INF;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf(" %c",&matrix[i][j]);
				if(matrix[i][j]=='a'){
					ax=i;
					ay=j;
				}
			}
		}
		dfs(ax,ay,0);
		if(mini<INF)
			cout<<mini<<endl;
		else
			cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
	}
	return 0;
}
void dfs(int x,int y,int cnt)
{
	if(x<0||x>=n||y<0||y>=m)//Խ��
		return;
	if(matrix[x][y]=='r'){
		if(cnt<mini)
			mini=cnt;
		return;
	}
	if(cnt>=mini||matrix[x][y]=='r')//��ʱ
		return;

	flag[x][y]=1;
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++){
			if(i+j==1||i+j==-1){
				if(matrix[x+i][y+j]!='#'&&!flag[x+i][y+j])
					if(matrix[x+i][y+j]=='x')
						dfs(x+i,y+j,cnt+2);//�򵽾���
					else
						dfs(x+i,y+j,cnt+1);
			}
		}
	flag[x][y]=0;
}
