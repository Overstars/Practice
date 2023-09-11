/*HDOJ2044 有一只经过训练的蜜蜂只能爬向右侧相邻的蜂房，不能反向爬行。请编程计算蜜蜂从蜂房a爬到蜂房b的可能路线数。
其中，蜂房的结构如下所示。*/
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
long long fun(long long x)//记忆化递归写法 
{
	if(x==1)
		return arr[x];
	else if(x==0)
		return arr[x];//从x到x也是一种走法 
	if(arr[x]!=0)
		return arr[x];
	else
		return arr[x]=fun(x-1)+fun(x-2);
}
