#include<stdio.h>
#include<ctype.h>
void clear(void);
int main(void)
{
	int n;
	char ch;
	while(scanf("%d",&n)!=EOF){
		while(n-->0){
			if(ch=getchar()!='_'&&isalpha(ch)!=1){
				printf("no\n");
				clear();
				continue;
			}
			while(ch=getchar()!='\n'){
				if(ch!='_'&&isalnum(ch)!=1){
					printf("no\n");
					clear();
					break;
				}
			}
			if(ch=='\n')
				printf("yes\n");
		}
	}
	return 0;
}
void clear(void)
{
	while(getchar()!='\n'){
		continue;
	}
}
