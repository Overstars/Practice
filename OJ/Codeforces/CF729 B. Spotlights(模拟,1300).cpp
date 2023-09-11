#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn][maxn],dp[maxn][maxn],nx[4]={1,0,-1,0},ny[4]={0,1,0,-1};
inline int fun(int x,int y,int n,int m)
{
	int cnt=0;
	for(int i=0;i<4;i++)
	{
		int xx=x+nx[i],yy=y+ny[i];
		while(xx>0&&xx<=n&&yy&&yy<=m)
			if(a[xx][yy])
			{
				cnt++;
				break;
			}
			else
				xx+=nx[i],yy+=ny[i];
	}
	return cnt;
}
int col[maxn],vis[maxn];//统计第i列有多少个1元素
int main()
{
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	for(int i=1;i<=n;i++)//每一行0元素右方向是否符合
	{
		bool flag=0,flag2=0;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j])
				flag=1;
			else if(flag)//0元素右方向
				ans++;
		}
		for(int j=m;j>0;j--)
		{
			if(a[i][j])
				flag2=1;
			else if(flag2)//0元素左方向
				ans++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		bool flag=0,flag2=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j][i])
				flag=1;
			else if(flag)//0元素上方向
				ans++;
		}
		for(int j=n;j>0;j--)
		{
			if(a[j][i])
				flag2=1;
			else if(flag2)//0元素下方向
				ans++;
		}
	}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			if(a[i][j]==0)
//			{
//				ans+=fun(i,j,n,m);
//			}
	cout<<ans<<endl;
	return 0;
}
