#include<stdio.h>
//����,�ٵ�n���ڵ�k����,k��n��,n-1��,ÿ��(n-2)��Ԫ�ش���,(n-1)*F[n-2]
//��k����n��,n-1��n-1��Ԫ�ش���
//�����ﲻ�壬Ҫ����ȷ�𰸸���
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
    if(m<(n-m))m=n-m;//ȡ����
    long long ans=1;
    for(i=m+1; i<=n; i++)ans*=i;
    for(i=1; i<=n-m; i++)ans/=i;
    return ans;
}
long long sum(long long n)
{
	long long ans=0,i;
	for(i=0;i<=n/2;i++){//�ϴ�����������һ��
		if(i==0)//�ϴ�0��
			ans+=1;
		else if(i==1&&n>=2)//�ϴ�һ��,�����ܷ���
			continue;
		else
			ans+=c(n,i)*F[i];//ѡ��i�˴���
	}
	return ans;
}
