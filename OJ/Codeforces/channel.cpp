#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t1,t2;
    while(cin>>t1>>t2)
	{
		ll sub1=(t1/60)*60;//来的那一集,t1-sub1本集开头少看的分钟
		ll sub2=(t2/60)*60;//结尾看的那一集开始,(t2-sub2)%51多看的
		ll ans=(sub2-sub1)/60*50;
		cout<<ans+(t2-sub2)%51-(t1-sub1)<<endl;
	}
	return 0;
}
