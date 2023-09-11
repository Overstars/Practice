#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
int arr[maxn],fa[maxn];
int findfa(int x)
{
	if(x!=fa[x])
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
	{
		fa[b]=a;
		arr[a]=min(arr[a],arr[b]);
		arr[b]=0;
//		printf("arr[%d]=%d\n",a,arr[a]);
	}
	else{
		fa[a]=b;
		arr[b]=min(arr[a],arr[b]);
		arr[a]=0;
//		printf("arr[%d]=%d\n",b,arr[b]);
	}
	return 1;
}
int main()
{
	int n,m,x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		cin>>arr[i];
	}
	while(m--)
	{
		cin>>x>>y;
		Merge(x,y);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans+=arr[i];
	cout<<ans<<endl;
	return 0;
}
