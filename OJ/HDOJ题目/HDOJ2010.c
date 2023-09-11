#include<stdio.h>
int main(void)
{
	int m,n;
	int a,b,c;
	while(scanf("%d %d",&m,&n)!=EOF){
		int d=0;
		for(m;m<=n;m++){
			a=m/100;//a为百位 
			b=m/10;
			b=b%10;//b为十位 
			c=m%10;//保存个位 
			if(m==a*a*a+b*b*b+c*c*c){
				if(d!=0)
					printf(" ");
				printf("%d",m);
				d++;
			}
		}
		if(d==0)
			printf("no");
		printf("\n");
	}
	return 0;
}
