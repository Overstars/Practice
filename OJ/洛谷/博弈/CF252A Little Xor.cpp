#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int now=a[i];
		ans=max(ans,a[i]);
		for(int j=i+1;j<=n;j++)
		{
			ans=max(ans,now^=a[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
