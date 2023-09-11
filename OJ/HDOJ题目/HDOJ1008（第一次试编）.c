#include<stdio.h>
int main(void)
{
	int n; 
	scanf("%d",&n);
	while(n>0)
	{
		int a=0,b=1,c=0,d=n,e=n,time=0;
		int i[n];
		for(a;a<=n;a++)
		i[a]=0;//初始化i[0]到i[n] 
		i[0]=0;//为i[0]赋值，便于进行循环 
		while(--d>=0){
			scanf("%d",&i[b++]);
		} //为 i[1]到i[n]赋值 
		while(c<e)
		{
			if(i[c]<i[c+1])
			{
				time=time+(i[c+1]-i[c])*6+5;//应该不会有两层相同的楼层吧？ 
				c++;
			 } 
			else
			{
				time=time+(i[c]-i[c+1])*4+5;
				c++;
			}
		}
		printf("%d\n",time);
		scanf("%d",&n);
	}
	return 0;
}
