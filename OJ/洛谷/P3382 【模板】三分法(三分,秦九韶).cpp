#include<bits/stdc++.h>
using namespace std;
const int maxn=20;
double a[maxn];//多项式系数(由低位到高)
double fun(double x,int n)//秦九韶算法求y值,常数优化复杂度O(n)
{
	double y=a[n];
	for(int i=n-1;i>=0;i--)//由高位向低位计算
		y=y*x+a[i];
	return y;
}
int main()
{
	freopen("P3382.in","r",stdin);
	int n;
	double l,r;
	cin>>n>>l>>r;
	for(int i=n;i>=0;i--)
		cin>>a[i];//由高到低输入
	double lmid,rmid,exp=1e-6;
	while(r-l>=exp)
	{
		lmid=l+(r-l)/3,rmid=r-(r-l)/3;
		if(fun(lmid,n)<fun(rmid,n))
			l=lmid;
		else
			r=rmid;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(5)<<l<<endl;
	return 0;
}
/*
 *二分只适用于单调函数查找
 *三分适用于单峰函数查找
 */
