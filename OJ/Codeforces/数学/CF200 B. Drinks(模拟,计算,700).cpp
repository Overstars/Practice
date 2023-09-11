#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n,tmp;
	cin>>n;
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		ans+=tmp;
	}
	cout<<setprecision(12)<<ans/n<<endl;
	return 0;
}
