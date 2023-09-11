#include<bits/stdc++.h>
using namespace std;
bool mp[6][6];
inline bool jud(int x,int y,int z)
{
	if(mp[x][y]&&mp[x][z]&&mp[y][z])
		return 1;
	if(!mp[x][y]&&!mp[x][z]&&!mp[y][z])
		return 1;
	return 0;
}
int main()
{//刚开始还以为是无向图三元环和补图三元环
	int m,u,v;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		mp[u][v]=mp[v][u]=1;
	}
	bool flag=0;//若找到,则为1
	for(int i=1;i<=5;i++)
	{
		for(int j=i+1;j<=5;j++)
		{
			for(int k=j+1;k<=5;k++)
			{
				if(jud(i,j,k))
				{
					flag=1;
					goto label;
				}
			}
		}
	}
	label:
		cout<<(flag?"WIN\n":"FAIL\n");
	return 0;
}
