#include<iostream>
#include<cstdio>
using namespace std;
double c[3005];
int main()//乍一看像递归，但其实不可以
{
	int n,i;
	double sum,a0,an1;
	while(cin>>n){
		sum=0;
		cin>>a0>>an1;
		for(i=1;i<=n;i++)
			scanf("%lf",&c[i]);
		for(i=n;i>0;i--)
			sum+=i*c[n-i+1];
		printf("%.2lf\n",(n*a0+an1-2*sum)/(n+1));
	}
	return 0;
}
//A(1)=(A0+A2)/2-C1=
