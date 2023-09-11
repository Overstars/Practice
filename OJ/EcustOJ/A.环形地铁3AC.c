#include<stdio.h>
long long a[200010]={0};
long long sum[100010]={0};
int main(void)
{
	int n,m;//n为地铁站数，m为询问次数 
	int x,y,i=0;
	
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);//a[i]为从i+1到下一站的时间 
//	for(i=0;i<n;i++)
//		sum+=a[i];
	for(i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i-1];//sum[i]为从第一站正向行驶到第i+1站的时间，sum[n]为绕行一周的时间 
	
	while(m-->0){
		int d;
		long long time1=0,time2=0,time=0;
		scanf("%d %d",&x,&y);//我觉得有必要比较下x,y的大小 
		if(x>y){
			d=y;
			y=x;
			x=d;
		}
//		for(x=x-1;x<y-1;x++){
//			time1+=a[x];//嵌套循环会导致超时 
//		}
		time1=sum[y-1]-sum[x-1];
		time2=sum[n]-time1;
		time=(time1<time2)?time1:time2;
		printf("%lld\n",time);
	}
	return 0;
}
