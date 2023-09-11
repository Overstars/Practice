#include<stdio.h>
#include<string.h>
int main(void)
{
	int n,i;
	char ch[4],ch2[4]={'2','0','5','0'};
	scanf("%d",&n);
	getchar();
	while(n-->0){
		memset(ch,0,sizeof(char));
		while(ch[0]!='\n'){
			for(i=0;i<4;i++){
				ch[i]=getchar();
			}
			if(strcmp(ch,ch2)==0)
				continue;
			else
			{
				printf("NO\n");
				break;
			}
			if(ch[0]=='\n'){
				printf("Yes\n");
			}
		}
	}
	return 0;
}
