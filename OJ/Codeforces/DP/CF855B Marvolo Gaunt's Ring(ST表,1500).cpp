#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll a[maxn],M[maxn][30],m[maxn][30];
void init(ll n)
{
	for(int i=1;i<=n;i++)
		M[i][0]=m[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			M[i][j]=max(M[i][j-1],M[i+(1<<(j-1))][j-1]);
			m[i][j]=min(m[i][j-1],m[i+(1<<(j-1))][j-1]);
		}
}
ll maxi(int l,int r)
{
	int k=log2(r-l+1);
	return max(M[l][k],M[r-(1<<k)+1][k]);
}
ll mini(int l,int r)
{
	int k=log2(r-l+1);
	return min(m[l][k],m[r-(1<<k)+1][k]);
}
int main()
{
	ll n,p,q,r,pa,qa,ra;
	cin>>n>>p>>q>>r;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	init(n);
	ll ans=LLONG_MIN;
	for(int i=1;i<=n;i++)
	{
		if(p>0)
			pa=p*maxi(1,i);
		else
			pa=p*mini(1,i);
		if(r>0)
			ra=r*maxi(i,n);
		else
			ra=r*mini(i,n);
		ans=max(ans,pa+q*a[i]+ra);
	}
	cout<<ans<<endl;
	return 0;
}
