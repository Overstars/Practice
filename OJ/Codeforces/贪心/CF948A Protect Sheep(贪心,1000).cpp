#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
char mp[maxn][maxn];
int n,m,nx[4]={1,0,-1,0},ny[4]={0,1,0,-1};
bool jud(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int xx=x+nx[i],yy=y+ny[i];
		if(xx<0||xx>n||yy<0||yy>m)
			continue;
		if(mp[xx][yy]=='S')
			return 1;
	}
	return 0;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>mp[i]+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]=='W'&&jud(i,j))
			{
				cout<<"No\n";
				exit(0);
			}
	cout<<"Yes\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(mp[i][j]=='.')
				cout<<"D";
			else
				cout<<mp[i][j];
		cout<<endl;
	}
	return 0;
}
