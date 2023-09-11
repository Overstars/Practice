#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long ans=0;
	for(long long i=1;i<1000;i++)
	{
		if(i%3==0||i%5==0)
			ans+=i;
	}
	cout<<ans<<endl;
	return 0;
}
