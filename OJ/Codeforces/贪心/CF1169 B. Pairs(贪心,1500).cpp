#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int arr[maxn][2],n,m;
bool jud(int x,int y)
{
	for(int i=0;i<m;i++)
	{
		if(arr[i][0]!=x&&arr[i][0]!=y&&arr[i][1]!=x&&arr[i][1]!=y)
			return 1;
	}
	return 0;
}
int main()
{
	int x=-1,y=-1,a,b,p=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>arr[i][0]>>arr[i][1];
	for(int i=0;i<m;i++)
	{
		if(arr[i][0]!=arr[i][1])
		{
			if(x==-1)
				x=i;
			else if(y==-1&&arr[i][0]!=arr[x][0]&&arr[i][0]!=arr[x][1]&&arr[i][1]!=arr[x][0]&&arr[i][1]!=arr[x][1])
			{
				y=i;
				break;
			}
		}
	}
	if(x>=0&&y>=0&&(jud(arr[x][0],arr[y][0])&&jud(arr[x][0],arr[y][1])&&jud(arr[x][1],arr[y][0])&&jud(arr[x][1],arr[y][1])))
		cout<<"NO\n";
	else
		cout<<"YES\n";
	return 0;
}
