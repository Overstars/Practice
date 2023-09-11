#include<stdio.h>
int main(void)
{
	char arr[105],max;
	while(scanf("%s",arr)!=EOF){
		int i;
		max=arr[0];
		for(i=0;arr[i]!='\0';i++){
			max=(max<arr[i])?arr[i]:max;
		}
		for(i=0;arr[i]!='\0';i++){
			putchar(arr[i]);
			if(arr[i]==max)
				printf("(max)");
		}
		printf("\n");
	}
	return 0;
}
