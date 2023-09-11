#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char name[100];
	int temp;
	double n;
	double sum=0,price;
	while(cin>>name){
		cin>>n>>price;
		sum+=n*price;
	}
	printf("%.1lf\n",sum);
	return 0;
}
