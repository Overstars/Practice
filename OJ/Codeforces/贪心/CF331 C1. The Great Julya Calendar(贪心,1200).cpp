#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,cnt=0;
	cin>>n;
	while(n>0)
	{
		cnt++;
		int x=n,tem=0;
		while(x)
		{
			tem=max(tem,x%10);
			x/=10;
		}
		n-=tem;
	}
	cout<<cnt<<endl;
	return 0;
}
