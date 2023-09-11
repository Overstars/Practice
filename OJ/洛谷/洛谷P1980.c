#include<stdio.h>
int main(void)
{
	unsigned long long a;
	int x,i,j,temp;
	while(scanf("%llu %d",&a,&x)!=EOF){
		i=0;
		for(j=1;j<=a;j++){
			temp=j;
			while(temp>0){
				if(temp%10==x){
					i++;
				}
				temp/=10;
			}
		}
		printf("%d\n",i);
	}
	return 0;
}
