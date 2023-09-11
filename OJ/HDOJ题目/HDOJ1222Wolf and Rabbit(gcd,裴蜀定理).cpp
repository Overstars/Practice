#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
	int r;
	if(a<b){
		r=a;
		a=b;
		b=r;
	}
	while((r=a%b)>0){
		a=b;
		b=r;
	}
	return b;
}
int main()
{
	int flag,t,m,n;
	cin>>t;
	while(t--){
		cin>>m>>n;
		if(gcd(m,n)>1)
			cout<<"YES"<<endl;//
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
//狼可以进去的位置p=(m*i)%n
//设第x次搜寻，转到第y圈，p=mx+ny，裴蜀定理
//p为gcd(m,n)整数倍,当且仅当存在整数x,y使上式成立
//所以gcd(m,n)==1,p可以为任意整数，否则p只能为gcd(m,n)的倍数
