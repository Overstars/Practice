#include<stdio.h>
#include<string.h>//strtok(char s[], const char *delim)�ɰ����ַ��ָ�,�״ε���ʱ,sָ��Ҫ�ֽ���ַ���,֮���ٴε���Ҫ��s���NULL��
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
