#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,ans=0;
	cin>>x;
	ans+=x/5;
	x%=5;
	ans+=x/4;
	x%=4;
	ans+=x/3;
	x%=3;
	ans+=x/2;
	x%=2;
	ans+=x;
	cout<<ans<<endl;
	return 0;
}
