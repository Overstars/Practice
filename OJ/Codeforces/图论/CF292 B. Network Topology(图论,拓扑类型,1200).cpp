#include<bits/stdc++.h>
using namespace std;
int deg[100005];
int main()
{
	int n,m,u,v,c1=0,c2=0,cn=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==1)
			c1++;
		else if(deg[i]==2)
			c2++;
		else
			cn++;
	}
	if(c1==2&&cn==0)
		cout<<"bus topology\n";
	else if(c1==0&&cn==0)
		cout<<"ring topology\n";
	else if(c2==0&&cn==1)
		cout<<"star topology\n";
	else
		cout<<"unknown topology\n";
	return 0;
}
