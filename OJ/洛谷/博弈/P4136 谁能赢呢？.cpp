#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n&&n)
		cout<<(n&1?"Bob":"Alice")<<endl;
	return 0;
}
