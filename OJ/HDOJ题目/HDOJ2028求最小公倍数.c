#include<stdio.h>
long long gcd(long long a,long long b);
long long lcm(long long a,long long b);
int main(void)
{
	int n;
	long long next;
	while(scanf("%d",&n)==1){
		long long commul=1;
		while(n-->0){
			scanf("%lld",&next);
			commul=lcm(commul,next);
		}
		printf("%lld\n",commul);
	}
	return 0;
}
long long gcd(long long a,long long b)//返回a,b最大公约数 
{
	long long r;
	if(a<b){
		r=b;
		b=a;
		a=r;
	}
	while((r=a%b)!=0){
		a=b;
		b=r;
	}
	return b;
}
long long lcm(long long a,long long b)//返回a,b的最小公倍数 
{
	long long multi=a*b;
	return multi/gcd(a,b);
}
