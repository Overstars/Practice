#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=100005,inf=0x3f3f3f3f;
int l[maxn][2];
bool vis[maxn];
signed main()
{
	int n,ans=0,tem,len;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>len;
		l[i][0]=inf;
		l[i][1]=-inf;
		int flag=1,res=inf;
		for(int j=1;j<=len;j++)
		{
			cin>>tem;
			if(!vis[i])
			{
				if(res<tem)
					ans+=2*n-1,vis[i]=1;//前面+后面
				res=min(res,tem);
			}
			l[i][0]=min(l[i][0],tem);
			l[i][1]=max(l[i][1],tem);
		}
	}
//	for(int i=1;i<=n;i++)
//		printf("%lld:MAX=%lld,min=%lld\n",i,l[i][0],l[i][1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(vis[i])
			{
				ans+=n;
				break;
			}
			else if(vis[j])
				continue;
			else if(l[i][0]<l[j][1])
				ans++;
	cout<<ans<<endl;
	return 0;
}
