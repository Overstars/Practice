#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int fibo[21]={0,1,1};
int main()
{
	double ans;
	int n;
	for(n=3;n<21;n++)
		fibo[n]=fibo[n-2]+fibo[n-1];
	while(cin>>n){
		if(n<21)
			cout<<fibo[n]<<endl;
		else{
			ans=-log10(sqrt(5))+n*log10((1+sqrt(5))/2);
			ans-=(int)ans;
			ans=pow(10,ans)*1000;
			printf("%d\n",(int)ans);
		}
	}
	return 0;
}
