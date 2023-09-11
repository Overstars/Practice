#include<stdio.h>
#define N 1000005
long long arr[N];//记录1到i的不幸数字个数
void unlucky(void);
int main(void)
{
	long long n,m;
	unlucky();
	while(scanf("%lld %lld",&n,&m)==2&&(n||m)){
		printf("%lld\n",m-n+1-(arr[m]-arr[n-1]));
	}
	return 0;
}
void unlucky(void)
{
	long long i,temp;
	for(i=1;i<N-2;i++){
		temp=i;
		arr[i]=arr[i-1];
		while(temp>0){
			if(temp%10==4||temp%100==62){
				arr[i]++;
				break;
			}
			temp/=10;
		}
	}
}
