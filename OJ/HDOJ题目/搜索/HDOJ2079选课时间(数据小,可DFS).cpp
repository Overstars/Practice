#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int maxn = 200010;//上大的模板
const int inf=0x3f3f3f3f;
int gra[10],ans;
int t,n,k;
void dfs(int sum,int now)
{
	if(sum>=n||now>k)
	{
		if(n==sum)
			ans++;
		return;
	}
	if(gra[now]>0)
	{
		gra[now]--;
		dfs(sum+now,now);
		gra[now]++;
	}
	dfs(sum,now+1);
}
int main()
{
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(gra,0,sizeof(gra));
		cin>>n>>k;
		for(int i=0;i<k;i++)
		{
			int a,b;
			cin>>a>>b;
			gra[a]=b;
		}
		dfs(0,1);
		cout<<ans<<endl;
	}
	return 0;
}
