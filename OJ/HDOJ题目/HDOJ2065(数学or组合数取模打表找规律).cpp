#include<cstdio>
#include<iostream>
using namespace std;
long long ans[30];
long long fun(int x);
long long c(long long n,long long m);
long long Mode(long long a,long long b,long long mode);
int main()
{
	long long n,i,t,flag=0,cnt;
	for(i=1;i<25;i++)
		ans[i]=fun(i);
//	for(i=1;i<100;i++){
//		printf("%d:%lld\n",i,ans[i]);
//	}
	while(scanf("%lld",&t)==1&&t!=0){
//		if(flag)
//			putchar('\n');
//		flag=1;
		for(i=1;i<=t;i++){//i����Ϊint����
			scanf("%lld",&n);
//			for(n=1;n<110;n++)
			if(n>=3)
				printf("Case %lld: %lld\n",i,ans[(n-3)%20+3]);
			else
				printf("Case %lld: %lld\n",i,ans[n]);
		}
		putchar('\n');
	}
	return 0;
}
long long fun(int x)
{
	long long sum = Mode(2,x,100);
	int i,j;
	for(i=1;i<=x/2;i++){
//		long long temp=(Mode(2,x-2*i,100)*(c(x,2*i)%100))%100;
//		for(j=0;j<=i;j++){
//			temp*=c(2*i,2*j)%100;
//		}
		long long temp=(Mode(2,x-2*i,100)*(c(x,2*i)%100)*(Mode(2,2*i-1,100)))%100;
		sum+=temp%100;
	}
	return sum%100;
}
long long c(long long n,long long m)//n=31ʱ�����?
{
    int i;//p��Ϊ�����������÷���С����
    if(m<(n-m))m=n-m;//ȡ����
    long long ans=1;
    for(i=m+1; i<=n; i++)ans=i*ans;
    for(i=1; i<=n-m; i++)ans/=i;
    return ans%100;
}
long long Mode(long long a,long long b,long long mode)//��a�ǵ�����b��ָ����mode��ȡģ��
{
	long long sum = 1;
	a = a % mode;
	while (b > 0) {
		if (b % 2 == 1)		//�ж��Ƿ����������������Ļ���������������ȳ���sum
			sum = (sum * a) % mode;
		b /= 2;
		a = (a * a) % mode;// ���ϵ������ϲ���ȡģ����Сa��b�Ĺ�ģ
	}
	return sum;
}
