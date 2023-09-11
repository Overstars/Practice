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
typedef long long ll;
const int inf=0x3f3f3f3f;
//#define DEBUG
struct node
{
	int st,ed;
} m[10005];
bool cmp(const node& a,const node& b)
{
	if(a.st<b.st)
		return 1;
	else if(a.st==b.st)
		return a.ed<b.ed;
	else
		return 0;
}
int dp[10005];//选择第i个任务的最小工作时间
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,k,ans=inf;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>m[i].st>>m[i].ed;
		m[i]+=m[i].st;
	}
	sort(m+1,m+k+1,cmp);
	dp[1]=m[1].ed-m[1].st;
	for(int i=2;i<=n;i++)
	{

	}
	cout<<n-ans<<endl;
	return 0;
}
