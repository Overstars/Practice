#include<stdio.h>
#include<ctype.h>
int main(void)
{
	int n;
	char ch,iden[50]={'\0'};
	while(scanf("%d",&n)!=EOF){
		int i,j;
		for(i=0;i<n;i++){
			j=0;
			while((iden[j]=getchar()!='\n'))
				j++;
			if(iden[0]!='_'||isalpha(iden[0])){
				printf("no\n");
				continue;
			}
			for(j=0;j<sizeof(iden);j++){
				if(iden[j]!=' '||isalnum(iden[j])){
					printf("no\n");
					continue;
				}
			}
			printf("yes\n");
			for(i=0;i<50;i++)
				iden[i]='\n';
		}
	}
	return 0;
}
