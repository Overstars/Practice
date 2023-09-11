#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y)//扩展欧几里得,要保证a>b
{//传递x,y的引用
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll r=exgcd(b,a%b,x,y);
	ll t=y;
	y=x-(a/b)*y;//(a/b)向下取整
	x=t;
	return r;
}
int main()
{
	ll a,b,x,y;
	cin>>a>>b;
	ll t=exgcd(a,b,x,y);
	cout<<(x/t%(b/t)+b/t)%(b/t);
	return 0;
}
