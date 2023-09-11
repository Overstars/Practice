#include<iostream>
#include<cstdio>
using namespace std;
long long ans[23]={0,3,9};
int main()
{
	int t,i;
	for(i=3;i<40;i++)
		ans[i]=2*ans[i-1]+ans[i-2];
	cin>>t;
	while(t--){
		cin>>i;
		cout<<ans[i]<<endl;
	}
	return 0;
}
