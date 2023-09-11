//#pragma GCC optimize(2)
//#pragma G++ optimize("O2") //O2优化
//#pragma comment(linker, "/STACK:102400000,102400000") //手动扩栈
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<climits>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
//#define lowbit(x) ((x) & -(x))
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=205;
//#define DEBUG
int mp[maxn][maxn],dis[maxn],lower[maxn];
bool intree[maxn];
int prim(int n,int s)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=mp[s][i];
		lower[i]=s;
		intree[i]=0;
	}
	intree[s]=1;
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		int t=s,dist=inf;
		for(int j=1;j<=n;j++)
		{
			if(!intree[j]&&dis[j]<dist)
			{
				dist=dis[j];
				t=j;
			}
		}
		if(t==s)
			break;
		intree[t]=1;
		ret+=dist;
		for(int j=1;j<=n;j++)
		{
			if(!intree[j]&&dis[j]>mp[t][j])
			{
				lower[j]=t;
				dis[j]=mp[t][j];
			}
		}
	}
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>mp[i][j];
		cout<<prim(n,1)<<endl;
	}
	return 0;
}
