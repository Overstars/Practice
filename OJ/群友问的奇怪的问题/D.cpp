#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
ll a[maxn],b[maxn],sum,cost,w;
double eps=1e-8;
bool check(double tim,ll n)
{
	double now=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=tim*b[i])
			continue;
		now+=tim*b[i]-a[i];
	}
	return w*tim>=now;
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll t=1,n;
//	cin>>t;
	while(t--)
	{
		cin>>n>>w;//每秒
		sum=0,cost=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];//初始,耗费
			swap(a[i],b[i]);
			sum+=a[i];
			cost+=b[i];
		}
		if(cost<=w)
		{
			cout<<-1<<endl;
			continue;
		}
		double l=0,r=1e14,ans=0;
		while(abs(r-l)>eps)
		{
			double mid=(l+r)/2;
//			cerr<<"mid = "<<mid<<endl;
			if(check(mid,n))
			{
				ans=max(ans,mid);
				l=mid;
			}
			else
				r=mid;
		}
		cout<<setiosflags(ios::fixed)<<setprecision(9)<<ans<<endl;
	}
	return 0;
}
