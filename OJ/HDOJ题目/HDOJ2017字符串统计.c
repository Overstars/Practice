#include<stdio.h>
#include<string.h>
int main(void)
{
	int n;
	scanf("%d",&n);
	while(n-->0){
	int i,count=0;
	char arr[1000];
	for(i=0;i<1000;i++)
		arr[i]='\0';
	scanf("%s",arr);
	for(i=0;i<strlen(arr);i++){
		if('0'<=arr[i]&&arr[i]<='9')
			count++;
	}
	printf("%d\n",count);
	}
	return 0;
}
