/*这题一开始似乎思路就是错的，9分26秒看题，10分59秒敲代码，28分钟修改……
*并未完成……*/
#include<stdio.h>
#define N 1005
#define M 1005
int min(int a,int b);
int func(int i,int m);
int form[N][M]={0},price[N]={0};
int main(void)
{
	int n,i,m;
	while(scanf("%d",&n)==1&&n!=0){
		for(i=0;i<n;i++)
			scanf("%d",&price[i]);
		scanf("%d",&m);
		printf("%d\n",func(n,m));
	}
	return 0;
}
int min(int a,int b)
{
	return (a<b)?a:b;
}
int func(int i,int m)
{
	int j,k;
	for(j=0;j<i;j++) form[j][0]=m;
	for(k=0;k<4;k++) form[0][k]=m;
	for(j=0;j<i;j++)
		for(k=0;k<m;k++){
			if(k<price[j]) form[j][k]=form[j-1][k];
			else
				form[j][k]=min(form[j-1][k],form[j-1][k-price[j]]-price[j]);
		}
	return form[i][m];
}
