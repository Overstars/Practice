#include<stdio.h>
#include<string.h>
int main()
{
	char s1[20],s2[10]="6";
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",s1);
		char *p=s1+strlen(s1)-5;
		strncpy(s2+1,p,7);
		printf("%s\n",s2);
	}
	return 0;
}
