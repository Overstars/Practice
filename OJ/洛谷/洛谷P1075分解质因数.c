/*���P1075 �������ֽ�
*��֪������n��n��������ͬ�������ĳ˻�������������нϴ���Ǹ�����
*˼·����2��ʼö����������������n����������*/
#include<stdio.h>
#include<math.h>
int MinPriFac(long long n);
int main(void)
{
	long long n;
	while(scanf("%lld",&n)==1){
		printf("%d\n",n/MinPriFac(n));
	}
	return 0;
}
int MinPriFac(long long n)
{
	int x,i;
	for(x=2;x<=sqrt(n);x++){
		for(i=2;i<x;i++){
			if(x%i==0)
				break;
		}
		if(i>=x){//��������ʱxΪ���� 
			if(n%x==0)
				break;
		}
	}
	return x;
}
