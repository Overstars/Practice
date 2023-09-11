#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int t;
	double x1,y1,x2,y2;
	cin>>t;
	while(t--){
		cin>>x1>>y1>>x2>>y2;
		printf("%.2lf\n",180/3.1415926*fabs(atan2(y1,x1)-atan2(y2,x2)));
	}
	return 0;
}
