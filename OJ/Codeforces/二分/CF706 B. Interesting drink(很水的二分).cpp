#include<bits/stdc++.h>
using namespace std;
int x[100005];
bool jud(int k,int m)
{
	if(x[k]<=m)
		return 1;
	else
		return 0;
}
int main()
{
	int n,q,m;
	cin>>n;//商店数量
	for(int i=1;i<=n;i++)
		cin>>x[i];//价格
	sort(x+1,x+n+1);
	cin>>q;//询问次数
	while(q--)
	{
		cin>>m;
		int l=0,r=n,mid,ans=0;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(jud(mid,m))
				l=mid+1,ans=mid;
			else
				r=mid-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
