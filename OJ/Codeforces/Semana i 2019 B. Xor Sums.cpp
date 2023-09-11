#include<bits/stdc++.h>
using namespace std;
int main()
{
//	int n,ans,x=1;
//	cin>>n;
//	while(x<=n)
//	{
//		ans=1;
//		for(int i=2;i<=x;i++)
//			ans^=i;
//		printf("xor[%d]=%d\n",x++,ans);
//	}
	long long t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%4==0)
			cout<<n<<endl;
		else if(n%4==1)
			cout<<1<<endl;
		else if(n%4==2)
			cout<<n+1<<endl;
		else
			cout<<0<<endl;
	}
	return 0;
}
