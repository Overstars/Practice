#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
	{
		cin>>n>>p;
		int tot=2*n+p;
		for(int i=1,cnt=0;i<=n&&cnt<tot;i++)
		{
			for(int j=i+1;j<=n&&cnt<tot;j++)
			{
				cout<<i<<' '<<j<<endl;
				cnt++;
			}
		}
	}
	return 0;
}
