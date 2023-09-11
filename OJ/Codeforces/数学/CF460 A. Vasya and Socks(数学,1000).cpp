#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,ans=0;
	cin>>n>>m;
	ans=n;
	n=n/m;
	if(n>0)
	{
		ans++;//n下一天
		for(;n>0;ans++)
		{
			if(ans%m==0)
				n++;
			n--;
			if(n==0)
				break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
