/*HDOJ2044 ��һֻ����ѵ�����۷�ֻ�������Ҳ����ڵķ䷿�����ܷ������С����̼����۷�ӷ䷿a�����䷿b�Ŀ���·������
���У��䷿�Ľṹ������ʾ��*/
#include<stdio.h>
long long fun(long long x);
long long arr[60]={1,1};
int main(void)
{
	int n;
	long long a,b;
	scanf("%d",&n);
	while(n-->0){
		scanf("%lld %lld",&a,&b);
		printf("%lld\n",fun(b-a));
	}
	return 0;
}
long long fun(long long x)//���仯�ݹ�д�� 
{
	if(x==1)
		return arr[x];
	else if(x==0)
		return arr[x];//��x��xҲ��һ���߷� 
	if(arr[x]!=0)
		return arr[x];
	else
		return arr[x]=fun(x-1)+fun(x-2);
}
