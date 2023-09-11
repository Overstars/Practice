#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//¿ØÖÆÊä³ö,<<setiosflags(ios::fixed)<<setprecision(9)
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
int ans,n,k;
void dfs(int pre,int x,int cnt)
{
	if(x==n)
	{
		if(cnt==k)
		{
			ans++;
		}
		return;
	}
//	printf("x=%d,cnt=%d\n",x,cnt);
	if(cnt>=k||x>=n)
		return;
	for(int i=pre;i<=n-x;i++)
	{
		dfs(i,x+i,cnt+1);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>k;
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
