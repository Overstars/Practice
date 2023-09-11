#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int lcm(int a,int b);
int gcd(int a,int b);
int main()
{
	int a,b;
	while(cin>>a>>b)
		cout<<lcm(a,b)<<endl;
	return 0;
}
int lcm(int a,int b)
{
	return (a*b)/gcd(a,b);
}
int gcd(int a,int b)
{
	if(a<b)
		swap(a,b);
	int r;
	while((r=a%b)){
		a=b;
		b=r;
	}
	return b;
}
