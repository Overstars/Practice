#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	while(n--)
	{
		cin>>m;
		if(m&1)
			cout<<"zs wins"<<endl;
		else
			cout<<"pb wins"<<endl;
	}
	return 0;
}
