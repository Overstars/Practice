#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(void)
{
	int n;
	char iden[55];
	scanf("%d",&n);
	getchar();
	while(n-->0){
		int j=0;
		gets(iden);
		if(iden[0]!='_'&&isalpha(iden[0])==0){
			printf("no\n");
			continue;
		}
		for(j=0;j<strlen(iden);j++){
			if(isalnum(iden[j])==0&&iden[j]!='_'){
				printf("no\n");
				break;				
			}
		}
		if(j==strlen(iden)) 
			printf("yes\n");
	}
	return 0;
}
