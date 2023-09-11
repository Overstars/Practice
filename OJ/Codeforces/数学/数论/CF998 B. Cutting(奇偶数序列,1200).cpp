#include<bits/stdc++.h>
using namespace std;
int a[105],ans[105]={0},cnt,pre[2][105];
int main()
{
	int n,b;
	cin>>n>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[a[i]%2][i]++;
		pre[0][i]+=pre[0][i-1];
		pre[1][i]+=pre[1][i-1];
	}
	for(int i=2;i<n;i++)
	{
		if(pre[0][i]==pre[1][i])
		{
			ans[cnt++]=(int)abs(a[i+1]-a[i]);
		}
	}
	sort(ans,ans+cnt);
//	for(int i=0;i<cnt;i++)
//		cout<<"ans["<<i<<"]="<<ans[i]<<endl;
	int c=0,tot=0;
	for(int i=0;i<cnt&&tot<=b;i++)
		if((tot+=ans[i])<=b)
			c++;
	cout<<c<<endl;
	return 0;
}
