#include<stdio.h>
#include<math.h>
int main(void)
{
	long long n,m,x,y,jud;
	while(scanf("%lld %lld",&n,&m)==2&&(n||m)){
		jud=n*n-4*m;
		if(jud<0){
			printf("No\n");
			continue;
		}
		else{
			x=(n+(long long)sqrt(jud))/2;
			y=(n-(long long)sqrt(jud))/2;
		}
		if(x+y==n&&x*y==m)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
