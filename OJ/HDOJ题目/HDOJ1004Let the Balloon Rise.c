#include<stdio.h>
#include<string.h>
char str[1005][20];
int main(void)
{
	int i,j,n,loc=-1;
	while(scanf("%d",&n)==1&&n){
		for(i=0;i<n;i++)
			scanf("%s",str[i]);
		int max=0;
		for(i=0;i<n;i++){
			int cnt=0;
			for(j=0;j<n;j++){
				if(strcmp(str[i],str[j])==0){
					cnt++;
				}
			}
			if(cnt>max){
				max=cnt;
				loc=i;
			}
		}
		printf("%s\n",str[loc]);
	}
	return 0;
}
