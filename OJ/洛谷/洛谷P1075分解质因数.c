/*洛谷P1075 质因数分解
*已知正整数n，n是两个不同的质数的乘积，试求出两者中较大的那个质数
*思路：从2开始枚举质数，若能整除n，输出这个商*/
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
		if(i>=x){//条件成立时x为质数 
			if(n%x==0)
				break;
		}
	}
	return x;
}
