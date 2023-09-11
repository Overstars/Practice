#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[22],in[22],out[22];
int main()
{
	ll a,n,m,x;
	cin>>a>>n>>m>>x;
	f[1]=f[2]=a;
	in[1]=in[2]=out[2]=a;
	for(int i=3;i<=x;i++)
	{//从第i站开出
		out[i]=in[i-1];
		in[i]=in[i-1]+in[i-2];
		f[i]=f[i-1]-out[i]+in[i];
	}
	cout<<f[x]<<endl;
	return 0;
}
