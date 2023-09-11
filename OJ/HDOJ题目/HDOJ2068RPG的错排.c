#include<stdio.h>
//错排,①第n个在第k个上,k在n上,n-1种,每种(n-2)个元素错排,(n-1)*F[n-2]
//②k不在n上,n-1种n-1个元素错排
//题意表达不清，要求正确答案个数
long long F[55]={0,0,1,2};
long long fun(long long n,long long m);
long long c(long long n,long long m);
long long sum(long long n);
int main(void)
{
	int i;
	for(i=4;i<27;i++){
		F[i]=(i-1)*(F[i-1]+F[i-2]);
	}
	long long n;
	while(scanf("%lld",&n)==1&&n){
		printf("%lld\n",sum(n));
	}
	return 0;
}
long long fun(long long n,long long m)
{
	if(m==0)
		return 1;
	if(m==1)
		return n;
	long long a=1,b=1,c=1,i;
	for(i=1;i<=n;i++){
		a*=i;
	}
	for(i=1;i<=m;i++){
		b*=i;
	}
	for(i=1;i<=n-m;i++){
		c*=i;
	}
	return a/(b*c);
}
long long c(long long n,long long m)
{
    int i;
    if(m<(n-m))m=n-m;//取大数
    long long ans=1;
    for(i=m+1; i<=n; i++)ans*=i;
    for(i=1; i<=n-m; i++)ans/=i;
    return ans;
}
long long sum(long long n)
{
	long long ans=0,i;
	for(i=0;i<=n/2;i++){//认错人数不超过一半
		if(i==0)//认错0人
			ans+=1;
		else if(i==1&&n>=2)//认错一人,不可能发生
			continue;
		else
			ans+=c(n,i)*F[i];//选出i人错排
	}
	return ans;
}
