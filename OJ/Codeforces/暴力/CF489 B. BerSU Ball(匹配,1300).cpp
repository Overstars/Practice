#include<bits/stdc++.h>
using namespace std;
const int maxn=106;
int a[maxn],b[maxn];
bool vis[maxn];
int main()
{
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	int ans=0,p=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(!vis[j]&&abs(a[i]-b[j])<=1)
			{
				ans++;
				vis[j]=1;
				break;
			}
	}
	cout<<ans<<endl;
	return 0;
}
