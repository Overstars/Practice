#include<stdio.h>
long long a[200010]={0};
long long sum[100010]={0};
int main(void)
{
	int n,m;//nΪ����վ����mΪѯ�ʴ��� 
	int x,y,i=0;
	
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);//a[i]Ϊ��i+1����һվ��ʱ�� 
//	for(i=0;i<n;i++)
//		sum+=a[i];
	for(i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i-1];//sum[i]Ϊ�ӵ�һվ������ʻ����i+1վ��ʱ�䣬sum[n]Ϊ����һ�ܵ�ʱ�� 
	
	while(m-->0){
		int d;
		long long time1=0,time2=0,time=0;
		scanf("%d %d",&x,&y);//�Ҿ����б�Ҫ�Ƚ���x,y�Ĵ�С 
		if(x>y){
			d=y;
			y=x;
			x=d;
		}
//		for(x=x-1;x<y-1;x++){
//			time1+=a[x];//Ƕ��ѭ���ᵼ�³�ʱ 
//		}
		time1=sum[y-1]-sum[x-1];
		time2=sum[n]-time1;
		time=(time1<time2)?time1:time2;
		printf("%lld\n",time);
	}
	return 0;
}
