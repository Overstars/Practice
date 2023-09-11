#include<iostream>
using namespace std;
int main()
{
	int n,arr[42]={1,1},sum=0,i;
	for(i=2;i<42;i++)
		arr[i]=(arr[i-1]*i)%2009;
	while(cin>>n)
		if(n>=42)
			cout<<0<<endl;
		else
			cout<<arr[n]<<endl;
	return 0;
}
//2009可以分解为7*7*42,所以42!一定含有2009,取模后为0
