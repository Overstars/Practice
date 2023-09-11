#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int x[maxn],sum[maxn];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		sum[i]=sum[i-1]+x[i];
	}
	int ans=0,a,b;
	for(int i=1;i<=n-k+1;i++)
	{
		for(int j=i+k;j<=n-k+1;j++)
		{
			int now=sum[j+k-1]-sum[j-1]+sum[i+k-1]-sum[i-1];
//			printf("%d,%d,%d\n",i,j,now);
			if(now>ans)
			{
				ans=now;
				a=i,b=j;
			}
		}
	}
	cout<<a<<' '<<b<<endl;
	return 0;
}
