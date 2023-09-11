#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	scanf("%d",&n);
	ll ans=0,tem;
	priority_queue<ll,vector<ll> ,less<ll> > QAQ;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&tem);
		QAQ.push(-tem);//先假设每天都买
		QAQ.push(-tem);
		ans+=tem+QAQ.top();//取出最便宜的买入价格
		QAQ.pop();//弹出两次才表示买入
	}
	cout<<ans<<endl;
	return 0;
}
