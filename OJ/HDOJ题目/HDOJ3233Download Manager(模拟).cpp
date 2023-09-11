#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long t,n,b,i,p,cnt=0;
	double sum,s;
	while(cin>>t>>n>>b&&t&&n&&b){
		sum=0;
		for(i=0;i<t;i++){
			cin>>s>>p;
			sum+=s*(100-p)/100/b;
		}
		printf("Case %lld: %.2lf\n\n",++cnt,sum);
	}
	return 0;
}
