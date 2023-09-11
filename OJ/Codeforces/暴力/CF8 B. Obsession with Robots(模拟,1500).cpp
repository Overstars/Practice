#include<bits/stdc++.h>
using namespace std;
const int maxn=305,inf=0x3f3f3f3f;
int mp[maxn][maxn],nx[4]={0,1,0,-1},ny[4]={1,0,-1,0};
int x=100,y=100,tim=0;
int jud(int x,int y)
{
	int ret=inf;
	for(int i=0;i<4;i++)
	{
		int xx=x+nx[i],yy=y+ny[i];
		ret=min(ret,mp[xx][yy]);
	}
	return ret;
}
int main()
{
	memset(mp,inf,sizeof(mp));
	string s;
	bool flag=0;
	cin>>s;
	mp[x][y]=++tim;
	for(auto &ch:s)
	{
		if(ch=='L')
			x--;
		if(ch=='R')
			x++;
		if(ch=='U')
			y++;
		if(ch=='D')
			y--;
		tim++;
		if(mp[x][y]<tim||jud(x,y)+1<tim)
		{
			flag=1;
			break;
		}
		mp[x][y]=tim;
	}
	cout<<(flag?"BUG\n":"OK\n");
	return 0;
}
