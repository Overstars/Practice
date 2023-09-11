#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
struct BinaryIndexTree
{
	ll c[maxn],sum[maxn],n;
	#define lowbit(x) ((x)&(-x))
	void add(int k,ll val)
	{
		for(int i=k;i<=n;i+=lowbit(i))
			c[i]+=val,sum[i]+=val*(k-1);
	}
	void radd(int l,int r,ll val)
	{
		add(l,val);
		add(r+1,-val);
	}
	ll query(int k)
	{
		ll ret=0;
		for(int i=k;i;i-=lowbit(i))
			ret+=c[i]*k-sum[i];
		return ret;
	}
} bit,bit2;
int main()
{
	int n,m,l,r,k,d,opt;
	cin>>n>>m;
	bit.n=n;
	for(int i=1;i<=n;i++)
		cin>>k,bit.radd(i,i,k);
	bit2.n=n;
	while(m--)
	{
		cin>>opt;
		if(opt==1)
		{
			cin>>l>>r>>k>>d;
			bit.radd(l,r,k);
			bit2.radd(l+1,r,d);
			ll len=r-l+1;
			ll sum=len*(len-1)/2*d;
			bit2.radd(r+1,r+1,-(len-1)*d);
		}
		else{
			cin>>l;
			//cerr<<"ans = "<<endl;
			cout<<bit.query(l)-bit.query(l-1)+bit2.query(l)<<endl;
		}
		//for(int i=1;i<=n;i++)
		//	cerr<<bit.query(i)-bit.query(i-1)+bit2.query(i)<<' ';
		//cout<<endl;
	}
	return 0;
}
