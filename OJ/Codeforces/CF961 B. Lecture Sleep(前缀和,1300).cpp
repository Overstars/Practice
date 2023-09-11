#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn],t[maxn],sum[maxn];
int main()
{
	int n,k,res=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>t[i];
	int ans=res;
	for(int i=1;i<=n;i++)
	{
		if(t[i])
		{
			res+=a[i];
			a[i]=0;//一个trick,使得这个不会计入新增
		}
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=k;i<=n;i++)
	{
		ans=max(ans,res+sum[i]-sum[i-k]);
	}
	cout<<ans<<endl;
	return 0;
}
