#include<bits/stdc++.h>
using namespace std;
bool dp[305][305][305][4];
bool ans[4]={0};
void dfs(int r,int g,int b)
{
	if(r==g&&b)
		ans[3]=1;
	if(r==b&&g)
		ans[2]=1;
	if(g==b&&r)
		ans[1]=1;
	if(ans[1]&&ans[2]&&ans[3])
		return;
	if(r&&r%2==0)
		dfs(r>>1,g,b);
	if(g&&g%2==0)
		dfs(r,g>>1,b);
	if(b&&b%2==0)
		dfs(r,g,b>>1);
	if(r&&g)
		dfs(r-1,g-1,b+1);
	if(r&&b)
		dfs(r-1,g+1,b-1);
	if(g&&b)
		dfs(r+1,g-1,b-1);
}
int main()
{
	int n,r=0,g=0,b=0;
	string s;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='R')
			r++;
		else if(s[i]=='G')
			g++;
		else
			b++;
	}
	dfs(r,g,b);
	if(ans[3])
		cout<<"B";
	if(ans[2])
		cout<<"G";
	if(ans[1])
		cout<<"R";
	return 0;
}
