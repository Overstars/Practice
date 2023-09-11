#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n==0)
	{
		cout<<1<<endl;
		exit(0);
	}
	n%=4;
	if(n==0)
		cout<<"6\n";
	else if(n==1)
		cout<<"8\n";
	else if(n==2)
		cout<<"4\n";
	else
		cout<<"2\n";
	return 0;
}
