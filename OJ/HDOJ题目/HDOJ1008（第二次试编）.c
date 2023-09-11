#include<stdio.h>
int main(void)
{
	const up=6;
	const down=4;
	const stop=5;
	int n;
	while(scanf("%d",&n)) 
	{
		int now=0,next;
		int time=0,a=0;
		if(n==0)
		break;//当n为0时，结束程序 
		for(a;a<n;a++)
		{
			scanf("%d",&next);
			if(now<next)
			{
				time=time+(next-now)*up+stop;
			}
			else
			{
				time=time+(now-next)*down+stop;
			}
			now=next;
		 } 
		printf("%d\n",time);
	}
	return 0; 
}
