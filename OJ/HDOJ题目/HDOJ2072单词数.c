#include<stdio.h>
#include<string.h>//strtok(char s[], const char *delim)可按多字符分割,首次调用时,s指向要分解的字符串,之后再次调用要把s设成NULL。
int fun(void);
char temp[105],str[1005][105];
int main(void)
{
	char *word;
	while(gets(temp)!=NULL){
		int cnt=0;
		if(temp[0]=='#')
			break;
		word=strtok(temp," ");
		while(word!=NULL){
//			puts(word);
			int i=0;
			for(i=0;i<cnt;i++){
				if(strcmp(str[i],word)==0)
					break;
			}
			if(i==cnt)
				strcpy(str[cnt++],word);
			word=(strtok(NULL," "));
		}
		printf("%d\n",cnt);
	}
	return 0;
}
