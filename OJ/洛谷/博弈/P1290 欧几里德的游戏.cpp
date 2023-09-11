#include<bits/stdc++.h>
using namespace std;
bool jud(int a,int b,bool ope)
{
	if(a%b==0||a>2*b)
		return ope;//本轮操作胜者
	else
		return jud(b,a%b,!ope);
}
int main()
{
	int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a<b)
			swap(a,b);
		if(jud(a,b,1))
			cout<<"Stan wins\n";
		else
			cout<<"Ollie wins\n";
	}
	return 0;
}
/*
 *设a不小于b
 *当a%b=0时,本轮操作者必胜
 *当a>2b时,本轮操作者可自行在(b,a%b)和(a%b+b,b)两类状态里选择
 *对于第二类状态,能且只能进行一次操作转化到第一种状态
 *所以本轮操作者有必胜策略
 *而当b<a<2*b时,本轮操作者只能将状态转移到(b,a%b)上
 *需要再进行下一次操作来判断
*/
