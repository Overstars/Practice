#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int main()
{
	int t,n,a,b;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a=inf,b=-inf;
		int l,r;
		while(n--)
		{
			cin>>l>>r;
			a=min(a,r);
			b=max(b,l);
		}
		if(b-a>0)
			cout<<b-a<<endl;
		else
			cout<<0<<endl;
	}
	return 0;
}
