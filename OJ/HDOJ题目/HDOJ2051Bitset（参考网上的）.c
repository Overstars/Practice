#include<stdio.h>
int main(void)
{
	int ten,a,array[10];
	while(scanf("%d",&ten)!=EOF){
		for(a=0;a<10;a++){
			array[a]=ten%2;
			ten/=2;
			if(ten==0)
			break;
		}
		for(a;a>=0;a--)
		printf("%d",array[a]);
		printf("\n");
	}
	return 0;
}
