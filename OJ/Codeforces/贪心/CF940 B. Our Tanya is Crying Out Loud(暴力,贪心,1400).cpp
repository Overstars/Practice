#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a,b,ans=0,cost=0;
int main()
{
	cin>>n>>k>>a>>b;//a:减1代价,b:除k代价
	ans=a*(n-1);
	while(n>1&&k>1)
	{
		if(n%k==0)
		{
			cost+=min(a*(n-n/k),b);
//			printf("%lld->%lld,c=%lld\n",n,n/k,cost);
			n/=k;
		}
		else
		{
			if(n<k)
			{
				cost+=a*(n-1);
				break;
			}
			cost+=a*(n%k);
//			printf("%lld->%lld,c=%lld\n",n,n-n%k,cost);
			n-=n%k;
		}
	}
	if(cost)
		ans=min(ans,cost);
	cout<<ans<<endl;
	return 0;
}
