#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%6)
			cout<<"October wins!"<<endl;
		else
			cout<<"Roy wins!"<<endl;
	}
	return 0;
}
