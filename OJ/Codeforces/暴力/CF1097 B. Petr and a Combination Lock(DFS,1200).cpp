#include<bits/stdc++.h>
using namespace std;
const int mod=360;
int n,flag=0,a[55];
void dfs(int x,int tot,int step)
{
	if(step>n||flag)
		return;
	if(((tot+a[x])%mod==0||(tot-a[x])%mod==0)&&x==n)
	{
		flag=1;
//		printf("%d:x=%d,tot=%d\n",step,x,tot);
		return;
	}
	dfs(x+1,(tot+a[x])%mod,step+1);
	dfs(x+1,(tot-a[x])%mod,step+1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,1);
	if(flag)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}
