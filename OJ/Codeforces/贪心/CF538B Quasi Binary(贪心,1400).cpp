#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>res;
	int n,ans=0,len=0;
	cin>>n;
	for(int tem=n;tem>0;len++)
		tem/=10;
	while(n)
	{
		int now=0;
		for(int i=1,tem=n,mod=10;now<=n&&i<=len;i++,mod*=10)
		{//得到n的第i位,mod=10^i
			int p=tem%mod/(mod/10);
			now=now+((p)?1:0)*(mod/10);
		}
		ans++;
		res.push_back(now);
//		printf("now=%d\n",now);
		n-=now;
	}
	cout<<ans<<endl;
	for(int v:res)
		cout<<v<<' ';
	return 0;
}
