#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double fun(double x)
{
	return 8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*x+6;
}
int main()
{
	int t;
	double l,r,y;
	cin>>t;
	while(t--){
		cin>>y;
		if(fun(0)<=y&&fun(100)>=y){
			l=0,r=100;
			double ans,a;
			while(r-l>1e-6){
				ans=(l+r)/2;
				a=fun(ans);
				if(a>y)
					r=ans;
				else if(a<y)
					l=ans;
				else
					break;
			}
			printf("%.4lf\n",ans);
		}
		else
			cout<<"No solution!"<<endl;
	}
	return 0;
}
