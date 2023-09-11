#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,inf=0x3f3f3f3f;
int c[maxn];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)
		ans=min(ans,i+c+n-upper_bound(c+1,c+n+1,2*c[i]));
	cout<<ans<<endl;
	return 0;
}
