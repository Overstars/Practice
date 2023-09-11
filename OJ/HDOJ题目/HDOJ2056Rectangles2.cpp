#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	double x1,x2,x3,x4,y1,y2,y3,y4;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4){
		if(x1>x2)//调成1左上2右下
			swap(x1,x2);
		if(y1<y2)
			swap(y1,y2);
		if(x3>x4)
			swap(x3,x4);
		if(y3<y4)
			swap(y3,y4);
		double lmax=max(x1,x3),rmin=min(x2,x4),umin=min(y1,y3),dmax=max(y2,y4);
		if(lmax>=rmin||dmax>=umin)
			printf("%.2lf\n",0.0);
		else{
			printf("%.2lf\n",(rmin-lmax)*(umin-dmax));
		}
	}
	return 0;
}

