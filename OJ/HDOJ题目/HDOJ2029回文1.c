#include<stdio.h>
#include<string.h>
int main(void)
{
	int n;
	char str[105];
	while(scanf("%d",&n)!=EOF){
		while(n-->0){
			int i,j;
			scanf("%s",str);
			for(i=0,j=strlen(str)-1;i<j;i++,j--){
				if(str[i]!=str[j])
					break;
			}
			if(i<j)
				printf("no\n");
			else
				printf("yes\n");
		}
	}
	return 0;
}
