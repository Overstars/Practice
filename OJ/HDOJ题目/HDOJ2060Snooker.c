//��������ֵģ����˵�Ĳ����
//���n<=6������ֻ������ɫ��������ʣ1���򣬷����յ÷���7��ʣ�������÷���6+7=13���Դ����ƣ����������յ÷���p+ʣ����ɫ��ĵ÷֡�
//���n>6�������к��������ɫ����ô���������յ÷���a+1*��n-6����ʾʣ�����÷�+7*��n-6����ʾ������ÿ�λ��к����ѡ����к������÷�+27��ʾ��������ɫ��÷ֻ�á�
#include<stdio.h>
#include<stdlib.h>
int main(void)
{

	long long n,ball,p,o;
	scanf("%lld",&n);
	while(n--){
		scanf("%lld %lld %lld",&ball,&p,&o);
		long long end=p;
		if(ball<=6)//ֻʣ����
		{
			int temp=7;
			while(ball--)
				end+=(temp--);//֮ǰ������ʲô���Դ�����Ŀ��û˵����
		}
		else
			end=p+(ball-6)*8+27;
		if(end>=o)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
