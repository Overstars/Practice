#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
ll v[maxn],u[maxn];
int main()
{
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		u[i]=v[i];
	}
	sort(u+1,u+n+1);
	for(int i=2;i<=n;i++)
	{
		v[i]+=v[i-1];
		u[i]+=u[i-1];
	}
	cin>>m;
	while(m--)
	{
		int ope,l,r;
		cin>>ope>>l>>r;
		cout<<((ope-1)?u[r]-u[l-1]:v[r]-v[l-1])<<endl;
	}
	return 0;
}
