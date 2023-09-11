#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[1020],x[1020];
long long gcd(long long a,long long b)
{
	if(a<b)
		swap(a,b);
	long long r;
	while((r=a%b)){
		a=b;
		b=r;
	}
	return b;
}
long long lcm(long long a,long long b)
{
	return (a*b)/gcd(a,b);
}
int main()
{
	long long n,m,flag;
	long long x1=0;
	while(cin>>n>>m){
		long long i;
		flag=0;
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		if(n>=2)
			x1=lcm(a[0],a[1]);
		else
			x[0]=a[0];
		for(i=2;i<n;i++)
			x1=lcm(x1,a[i]);
		long long sum=0;
		for(i=0;i<n;i++){
			x[i]=x1/a[i];
			sum+=x[i];
		}
		if(n==1){
			cout<<"Yes"<<endl;
			printf("%lld\n",x[0]);
		}
		else if(m%sum==0){
			long long p=m/sum;
			cout<<"Yes"<<endl;
			printf("%lld",p*x[0]);
			for(i=1;i<n;i++)
				printf(" %lld",p*x[i]);
			putchar('\n');
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
