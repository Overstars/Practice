#include<stdio.h>
int main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF){
		float m;
		int a=0,b=0,c=0;//分别为正数/负数/零的个数 
		if(n==0)
		continue;
		while(n-->0){
			scanf("%f",&m);
			if(m>0)
			a++;
			else if(m==0)
			b++;
			else
			c++;
		}
		printf("%d %d %d\n",c,b,a);
	}
	return 0;
}
