#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int cor(double a,double b,double c,double d);
double fmin(double a,double b);
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
		if(cor(x1,x2,x3,x4)==1&&cor(y2,y1,y4,y3)==1){//角重合
//			cout<<setiosflags(ios::fixed)<<setprecision(2)<<(fmin(x2-x3,x4-x1)*fmin(y3-y2,y1-y4))<<endl;
			printf("%.2lf\n",(fmin(x2-x3,x4-x1)*fmin(y3-y2,y1-y4)));
		}
		else if(cor(x1,x2,x3,x4)==2&&cor(y2,y1,y4,y3)==2){//完全在里面,输出较小的方块面积
//			cout<<setiosflags(ios::fixed)<<setprecision(2)<<fmin((x2-x1)*(y1-y2),(x4-x3)*(y3-y4))<<endl;
			printf("%.2lf\n",fmin((x2-x1)*(y1-y2),(x4-x3)*(y3-y4)));
		}
		else if(cor(x1,x2,x3,x4)==2&&cor(y2,y1,y4,y3)==1){//较小的方块底*相交的高
//			cout<<setiosflags(ios::fixed)<<setprecision(2)<<fmin((x2-x1),(x4-x3))*fmin(y3-y2,y1-y4)<<endl;
			printf("%.2lf\n",fmin((x2-x1),(x4-x3))*fmin(y3-y2,y1-y4));
		}
		else if(cor(x1,x2,x3,x4)==0||cor(y2,y1,y4,y3)==0)//不相交
			cout<<setiosflags(ios::fixed)<<setprecision(2)<<0.00<<endl;
		else{
//			cout<<setiosflags(ios::fixed)<<setprecision(2)<<fmin((y1-y2),(y3-y4))*fmin(x2-x3,x4-x1)<<endl;
			printf("%.2lf\n",fmin((y1-y2),(y3-y4))*fmin(x2-x3,x4-x1));
		}
	}
	return 0;
}
int cor(double a,double b,double c,double d)//前两而是一个正方形的平行边,从下到上，先左后右
{
	if((a<c&&c<b&&b<d)||(c<a&&a<d&&d<b))
		return 1;
	else if((a<c&&b>d)||(c<a&&d>b))
		return 2;
	return 0;//无交点
}
double fmin(double a,double b)
{
	return (a<b)?a:b;
}
