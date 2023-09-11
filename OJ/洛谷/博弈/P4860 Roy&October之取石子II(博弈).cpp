#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%4==0)
			cout<<"Roy wins!"<<endl;
		else
			cout<<"October wins!"<<endl;
	}
	return 0;
}
