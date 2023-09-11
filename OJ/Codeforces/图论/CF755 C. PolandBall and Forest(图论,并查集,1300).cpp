#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int fa[maxn];
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
		fa[b]=a;
	else
		fa[a]=b;
	return 1;
}
int main()
{
	int n,p;
	cin>>n;
	for(int i=1;i<=n;i++)
		fa[i]=i;
//		cin>>p[i];//树上离i最远的节点编号
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>p;
		if(Merge(i,p))
			ans--;
	}
	cout<<ans<<endl;
	return 0;
}
