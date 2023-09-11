#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m;
	cin>>n>>m;
	vector<ll> x(n),v;//n棵圣诞树位置,答案
	map<ll,ll> mp;//该位置距离圣诞树的距离
	queue<ll> QAQ;
	for(ll i=0;i<n;i++)
	{
		cin>>x[i];
		mp[x[i]]=0;
		QAQ.push(x[i]);
	}//通过在mp中查找位置来确定是否被占用
//	sort(x.begin(),x.end());
	ll ans=0;
	while(m>0)
	{
		ll now=QAQ.front();
		QAQ.pop();
		if(mp[now]>0)//0是圣诞树
		{
			ans+=mp[now];
			m--;
			v.push_back(now);
		}
		if(mp.count(now-1)==0)
		{
			mp[now-1]=mp[now]+1;
			QAQ.push(now-1);
		}
		if(mp.count(now+1)==0)
		{
			mp[now+1]=mp[now]+1;
			QAQ.push(now+1);
		}
	}
	cout<<ans<<endl;
	for(auto &i:v)
		cout<<i<<' ';
	return 0;
}
