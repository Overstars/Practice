#include<stdio.h>
#include<string.h>
char str[2005],st[2005];
int main(void)
{
	while(scanf("%s %s",str,st)==2&&str[0]!='#'){
		int cnt=0,i;
		for(i=0;i<strlen(str);i++){
			if(strncmp(&str[i],st,strlen(st))==0){
				cnt++;
				i+=strlen(st)-1;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
