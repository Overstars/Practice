#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,ans=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		if(n<4||n==5||n==7||n==11)
		{
			cout<<-1<<endl;
			continue;
		}
		if(n&1)//由4/6来凑
			n-=9,ans++;
		if(n%4==0)
			cout<<ans+n/4<<endl;
		else{
			while(n%4!=0)
				n-=6,ans++;
			cout<<ans+n/4<<endl;
		}
	}
	return 0;
}
