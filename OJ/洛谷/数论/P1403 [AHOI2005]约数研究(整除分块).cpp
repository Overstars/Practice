#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0;
	cin>>n;
	for(int l=1,r=1;l<=n;l=r+1)
	{
		r=n/(n/l);
		ans+=(r-l+1)*(n/l);//这个区间所有的值都为n/l向下取整
	}
	cout<<ans<<endl;
	return 0;
}
