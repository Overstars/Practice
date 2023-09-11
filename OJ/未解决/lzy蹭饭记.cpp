#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct node
{
	int st,ed,w;
} a[maxn];
bool cmp1(const node &a,const node &b)
{
	return a.st<b.st;
}
bool cmp2(const node &a,const node &b)
{
	return a.ed<b.ed;
}
int dp[maxn];
int main()
{
	int n;
	while(cin>>n)
	{
		int ma=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			cin>>a[i].st>>a[i].ed>>a[i].w,ma=max(ma,a[i].ed);
		sort(a+1,a+n+1,cmp1);
		stable_sort(a+1,a+n+1,cmp2);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i].st;j++)
			{
				dp[a[i].ed]=max(dp[a[i].ed],dp[j]+a[i].w);
			}
			for(int j=a[i].ed;j<=ma;j++)
				dp[j]=max(dp[j],dp[a[i].ed]);
			ans=max(ans,dp[a[i].ed]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
