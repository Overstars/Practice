#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t,n;
	double sum;
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		for(int i=n;i>1;i--)
			sum+=log10(i);
		cout<<(int)sum+1<<endl;
	}
	return 0;
}
//设a有x位,则10^x-1<=a<10x,解得log10(a)<x<=log10(a)+1
//x=(int)log10(a)+1
//用log(AB)=log(A)+log(B)化简计算
