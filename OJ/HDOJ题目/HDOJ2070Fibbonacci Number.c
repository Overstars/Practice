#include<stdio.h>
long long F[52]={0,1};
int main(void)
{
	int i,n;
	for(i=2;i<52;i++)
		F[i]=F[i-1]+F[i-2];
	while(scanf("%d",&n)==1&&n!=-1){
		printf("%lld\n",F[n]);
	}
	return 0;
}
