//#pragma G++ optimize("O2")
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
using namespace std;
const int maxn = 305;
const int INF=0x3f3f3f3f;//KM算法:带权的二分图中寻找*权值和最大*的完备匹配
int cost[maxn][maxn];//A[i]连接B[j]的权值
int lx[maxn], ly[maxn];
int match[maxn], slack[maxn];//B[i]匹配到的A,
int previous[maxn];
bool vy[maxn];//匹配过
void augment(int root,int n)
{
	fill(vy + 1, vy + n + 1, false);
	fill(slack + 1, slack + n + 1, INF);
	int py;
	match[py = 0] = root;
	do
	{
		vy[py] = true;
		int x = match[py], yy;
		int delta = INF;
		for (int y = 1; y <= n; y++)
		{
			if (!vy[y])
			{
				if (lx[x] + ly[y] - cost[x][y] < slack[y])
					slack[y] = lx[x] + ly[y] - cost[x][y], previous[y] = py;
				if (slack[y] < delta)
					delta = slack[y], yy = y;
			}
		}
		for (int y = 0; y <= n; y++)
		{
			if (vy[y])
				lx[match[y]] -= delta, ly[y] += delta;
			else
				slack[y] -= delta;
		}
		py = yy;
	}
	while(match[py] != -1);
	do
	{
		int pre = previous[py];
		match[py] = match[pre], py = pre;
	} while (py);
}
int KM(int n)
{
	for (int i = 1; i <= n; i++)
	{
		lx[i] = ly[i] = 0;
		match[i] = -1;
		for (int j = 1; j <= n; j++)
			lx[i] = max(lx[i], cost[i][j]);
	}
	int answer = 0;
	for (int root = 1; root <= n; root++)
		augment(root,n);
	for (int i = 1; i <= n; i++)
		answer += lx[i], answer += ly[i];
	return answer;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	while(~scanf("%d",&n))//不要用cin/cout
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&cost[i][j]);
		printf("%d\n",KM(n));
	}
	return 0;
}
