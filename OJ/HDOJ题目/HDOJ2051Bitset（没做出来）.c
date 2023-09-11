#include<stdio.h>
int tentotwo(int x);
int main(void)
{
	int ten;
	while(scanf("%d",&ten)!=EOF){
		tentotwo(ten);
	}
	return 0;
}

int tentotwo(int x)
{
	int arrey[10000],i=0;
	while(x>1){
		arrey[i]=x%2;
		i++;
	}
	printf("%d",x);
	while(i>=0){
		printf("%d",arrey[i]);
		i--;
	}
	printf("\n");
	return 0;
}
