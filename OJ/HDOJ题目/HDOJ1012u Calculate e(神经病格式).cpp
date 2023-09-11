#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include <iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
double e[10]={1,2,2.5};
int main()
{
	double tem=1;
	for(int i=2;i<10;i++)
	{
		tem*=i;
		e[i]=e[i-1]+(double)1/tem;
	}
	printf("n e\n- -----------\n");
	for(int i=0;i<5;i++)
		cout<<i<<' '<<setprecision(10)<<e[i]<<endl;//<<setiosflags(ios::fixed)
	for(int i=5;i<10;i++)
		cout<<i<<' '<<setiosflags(ios::fixed)<<setprecision(9)<<e[i]<<endl;//
	return 0;
}
