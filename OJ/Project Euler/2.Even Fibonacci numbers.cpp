#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[1000]={1,1};
int main()
{//4E6范围内
	ll ans=0;
	for(int i=2;i<100;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>4000000)
			break;
		if(f[i]%2==0)
			ans+=f[i];
		printf("%d:%lld\n",i,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}
