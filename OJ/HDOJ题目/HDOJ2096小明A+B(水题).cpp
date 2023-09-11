#include<iostream>
using namespace std;
int main()
{
	long long a,b;
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<((a+b)%100)<<endl;
	}
	return 0;
}
