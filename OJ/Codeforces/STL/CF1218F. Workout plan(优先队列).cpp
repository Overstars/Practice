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
ll x[maxn],c[maxn],pur[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n;//锻炼n天，初始为k
	ll minc=inf,cost=0,a,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	cin>>a;//一个饮料提升数值
	for(int i=1;i<=n;i++)
		cin>>c[i];//第i天购买饮料的成本
	bool flag=1;
	priority_queue<ll, vector<ll>, greater<ll> > QAQ;
	for(int i=1;i<=n;i++)
	{
		QAQ.push(c[i]);//推入小根堆
		while(k<x[i]&&!QAQ.empty())
		{
			minc=QAQ.top();
			QAQ.pop();
			cost+=minc;//新增开销,找到之前没买的最便宜的
			k+=a;
		}
		if(k<x[i])
		{
			flag=0;
			break;
		}
	}
	cout<<(flag?cost:-1)<<endl;
	return 0;
}
