#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[105];
	int n;
	scanf("%d",&n);
	getchar();
	while(n-->0){
		fgets(str,105,stdin);
		int i,arr[5]={0};
		for(i=0;i<strlen(str);i++){
			if(str[i]=='a') arr[0]++;
			else if(str[i]=='e') arr[1]++;
			else if(str[i]=='i') arr[2]++;
			else if(str[i]=='o') arr[3]++;
			else if(str[i]=='u') arr[4]++;
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",arr[0],arr[1],arr[2],arr[3],arr[4]);
		if(n!=0)
			printf("\n");
	}
	return 0;
}
