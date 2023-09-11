#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//¿ØÖÆÊä³ö,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
long long gcd(long long a,long long b)
{
	if(a<b)
		swap(a,b);
	long long r;
	while((r=a%b)){
		a=b;
		b=r;
	}
	return b;
}
int main()
{
	int t,n,m,a,b;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long ans=1,tem;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&tem);
			ans*=tem/gcd(ans,tem);
		}
		cout<<ans<<endl;
	}
	return 0;
}
