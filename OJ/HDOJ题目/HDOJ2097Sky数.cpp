//http://acm.hdu.edu.cn/showproblem.php?pid=2097
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int m,sum1=0,sum2,sum3,tem;
	while(cin>>m&&m){
		sum1=m%10+(m/10)%10+(m/100)%10+(m/1000);
		tem=m;
		sum2=0;
		for(;tem>0;tem/=12){
			sum2+=tem%12;
		}
		sum3=0;
		tem=m;
		for(;tem>0;tem/=16){
			sum3+=tem%16;
		}
		if(sum1==sum2&&sum1==sum3)
			cout<<m<<" is a Sky Number."<<endl;
		else
			cout<<m<<" is not a Sky Number."<<endl;
	}
	return 0;
}
