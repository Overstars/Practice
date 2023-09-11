#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e6+5;
ll inv[maxn],mod,n;
int main()
{
	cin>>n>>mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;i++)
		cout<<inv[i]<<'\n';
	return 0;
}
