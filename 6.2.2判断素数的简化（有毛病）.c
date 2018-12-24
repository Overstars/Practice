#include<stdio.h>
#include<math.h>
int isPrime(int x);

int main(void)
{
	int a;
	while(scanf("%d",&a))
	{
		if(isPrime(a)){ 
			printf("%d是素数\n",a);
		} 
		else{ 
			printf("%d不是素数\n",a);
		} 
	}
	return 0;
}

int isPrime(int x)
{
	int ret=1,i;
	if(x=1||(x%2==0&&x!=2)){
	ret=0;
	}
	if(ret==1){ 
	for(i=3;i<sqrt((double)x);i+=2){
		if(x%i==0){
			ret=0;
			break;
		}
		}		
	}
	return ret;
}


