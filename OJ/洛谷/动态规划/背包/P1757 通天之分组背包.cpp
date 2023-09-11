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
typedef long long ll;
const int inf=0x3f3f3f3f;
//#define DEBUG
struct node
{
	int weight,value;
	node(int weight,int value):
			weight(weight),value(value){}
};
int dp[1005][1005];
vector<node> g[1005];//g[i][j]表示i组第j个物品
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n,m;//n件物品，背包容量m
	map<int,int> TAT;
	cin>>m>>n;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(TAT[c]==0)
		{
			TAT[c]=++cnt;
		}
		g[TAT[c]].push_back(node(a,b));
	}
	for(int k=1;k<=cnt;k++)//遍历k组,每组是一个01背包
	{
		for(int j=m;j>=0;j--)//枚举容量
		{
			for(int i=0;i<g[k].size();i++)//第k组的第i件物品
			{
				if(j>=g[k][i].weight)//在第k组选择一个物品或不选
					dp[k][j]=max(dp[k][j],max(dp[k-1][j],dp[k-1][j-g[k][i].weight]+g[k][i].value));
				else
					dp[k][j]=max(dp[k][j],dp[k-1][j]);
			}
		}
	}
	cout<<dp[cnt][m]<<endl;
	return 0;
}
