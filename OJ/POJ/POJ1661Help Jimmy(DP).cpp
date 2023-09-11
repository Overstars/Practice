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
#define PI 3.14159265358979323846
#define e  2.7182818284590452354
#define ln_2 0.69314718055994530942
#define ln_10 2.30258509299404568402
const int inf=0x3f3f3f3f;
struct node
{
	int x1,x2,h;
} plat[1005];
int n,lim;
bool cmp(node a,node b)
{
	return a.h>b.h;//h高的在前
}
int dp[1005][2];//第i个板子向左/右到达下一个板子花费的时间
int goleft(int m)//m为当前所在板编号
{
	int nex=m+1;
	while(nex<=n&&plat[i].h-plat[nex].h<=lim)
	{
		if(plat[nex].x1<=plat[m].x1&&plat[nex].x2>=plat[m].x1)
		{
			dp[i][0]=plat[i].h-plat[nex].h+min();
			return;
		}
	}
	if(nex==n+1)
	{

	}
}
int solve()
{
	for(int i=0;i<n;i++)
	{

	}
	return dp[0][0];
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int t,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>y>>lim;
		for(int i=1;i<=n;i++)
		{
			cin>>plat[i].x1>>plat[i].x2>>plat[i].h;
		}
		sort(plat+1,plat+n+1,cmp);
		plat[0].x1=plat[0].x2=x,plat[0].h=y;
		memset(dp,inf,sizeof(dp));
		cout<<solve()<<endl;
	}
	return 0;
}
