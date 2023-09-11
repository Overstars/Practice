#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
ll c[maxn],dp[maxn];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>c[i];
		sort(c+1,c+n+1);
		dp[1]=c[1];
		dp[2]=c[2];
		for(int i=3;i<=n;i++)
			dp[i]=min(dp[i-1]+c[1]+c[i],dp[i-2]+c[1]+2*c[2]+c[i]);
		cout<<dp[n]<<endl;
	}
	return 0;
}

