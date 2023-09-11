#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,i,c,d,p,nl,np;
	cin>>n>>k>>i>>c>>d>>p>>nl>>np;
	int ans=0x3f3f3f3f;
	ans=min(ans,(c*d)/n);
	ans=min(ans,k*i/nl/n);
	ans=min(ans,p/np/n);
	cout<<ans<<endl;
	return 0;
}
