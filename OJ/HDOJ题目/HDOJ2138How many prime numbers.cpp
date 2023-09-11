#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int isprime(int x);
int main()
{
	int n,x,cnt=0;
	while(cin>>n&&n){
		cnt=0;
		while(n--){
			cin>>x;
			if(isprime(x))
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
int isprime(int x)
{
	if(x<2)
		return 0;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}
