#pragma G++ optimize("O2")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>
//#define lowbit(x) ((x) & -(x))
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=100005;
//#define DEBUG
//bool cmp(const node &a,const node &b)
//{
//	return a.no<b.no;
//}
int a[maxn],b[maxn],c[maxn];
bool vis[maxn],rec[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,cnt=0,M=0;//暴力O(n^2)做法TLE
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];//第i辆入洞的车为a[i]
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];//第i辆出洞的车为b[i]
		c[b[i]]=i;//c[i]表示编号为i的车第c[i]个出洞
	}
	for(int i=2;i<=n;i++)
	{
		M=max(M,c[a[i-1]]);
		if(c[a[i]]<M)
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
/*
 *n辆小汽车通过隧道
 *给你进入顺序与出洞顺序,找出有多少车有超车行为
 *时间1s,数据1e5m暴力做法肯定超时
 *做法：记录a[i]对应的出洞时间c[i]
 *遍历到a[i]时,如果存在一辆车进入的比a[i]早,出来的比a[i]晚
 *说明a[i]存在超车行为
*/
