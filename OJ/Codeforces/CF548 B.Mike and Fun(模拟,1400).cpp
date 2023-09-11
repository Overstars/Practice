#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int a[maxn][maxn];
int main()
{
	int n,m,t,x,y;
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	while(t--)
	{
		cin>>x>>y;
		a[x][y]=1-a[x][y];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int cnt=0;
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==0)
					cnt=0;
				else
					cnt++;
				ans=max(ans,cnt);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
