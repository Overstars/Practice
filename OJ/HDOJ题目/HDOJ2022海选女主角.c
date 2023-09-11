#include<stdio.h>
long long llabs(long long x);
int main(void)
{
	long long temp,real=0,m,n,i,j,max=0,row=1,col=1;
	while(scanf("%lld %lld",&m,&n)==2){
		real=0,max=0,row=1,col=1;
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				scanf("%lld",&temp);
				if(llabs(temp)>max){
					row=i;
					col=j;
					max=llabs(temp);
					real=temp;
				}
//				printf("i:%lld j:%lld\n",i,j);
//				printf("row=%lld col=%lld real=%lld max=%lld\n",row,col,real,max);
			}
		}
		printf("%lld %lld %lld\n",row,col,real);
	}
	return 0;
}
long long llabs(long long x)
{
	if(x<0)
		return -x;
	else
		return x;
}
