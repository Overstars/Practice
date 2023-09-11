#include<stdio.h>
#include<ctype.h>
#define STLEN 150
int main(void)
{
	char str[STLEN];
	int inword,i;
	while(fgets(str,STLEN,stdin)!=NULL){
		for(i=0;i<STLEN;i++){
			inword=0;
			if(islower(str[i])!=0&&inword==0){
				str[i]-=32;
				inword=1;
			}
			while((isalpha(str[i])!=0&&inword==1)||(isalpha(str[i])==0&&inword==0)){
				i++;
			}
		}
		fputs(str,stdout);
	}
	return 0;
}
