//����һ������1��2��3����n����Ĺ����Ǽ������п��ܵ������У������еĺ���m��
//�ɵȲ�������͹�ʽ�������ǰx��֮��>=M,Sn=(n^2+n)/2>=M
#include<stdio.h>
#include<math.h>
int main(void)
{
	long long n,m;
	while(scanf("%lld %lld",&n,&m)==2&&n!=0&&m!=0){
		long long i=(long long)sqrt((double)2*m);
		for(;i>0;i--){
			long long x=m/i-(i-1)/2;//�����x��ʼi���==m
			if(i*(2*x+i-1)==2*m)
				printf("[%lld,%lld]\n",x,x+i-1);
		}
		putchar('\n');
	}
	return 0;
}
