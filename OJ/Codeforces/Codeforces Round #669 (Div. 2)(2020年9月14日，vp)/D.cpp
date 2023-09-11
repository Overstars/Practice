//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=3e5+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int h[maxn],dp[maxn];
vector<int>v1,v2;
void bfs(int st,int n)
{
	queue<int>q;
	q.push(st);
	dp[st]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(x==n)
			return;
		if(dp[x+1]>dp[x]+1)
		{
			dp[x+1]=dp[x]+1;
			q.push(x+1);
		}
		int inc=1,M,mi;//增加,记录最小值
		if(h[x+1]<h[x])//减少,记录最大值
			inc=0;
		M=mi=h[x+1];
		for(int i=x+2;i<=n;i++)
		{
			if(inc&&mi>h[i])//增,且
			{
				if(dp[i]>dp[x]+1)
				{
					dp[i]=dp[x]+1;
					q.push(i);
				}
			}
			if(!inc&&M<h[i])//减
			{
				if(dp[i]>dp[x]+1)
				{
					dp[i]=dp[x]+1;
					q.push(i);
				}
			}
			if((inc&&h[i]<=h[x])||(!inc&&h[i]>=h[x]))
				break;
			M=max(M,h[i]);
			mi=min(mi,h[i]);
		}
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	memset(dp,inf,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
//	bfs(1,n);
	stack<int>s1,s2;//1维护递增,2维护递减
	s1.push(1),s2.push(1);
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		while(!s1.empty()&&h[s1.top()]>h[i])
		{//s1维护左面比h[i]矮的位置
			dp[i]=min(dp[i],dp[s1.top()]+1);
			s1.pop();
		}
		if(!s1.empty())
		{
			dp[i]=min(dp[i],dp[s1.top()]+1);
			if(h[s1.top()]==h[i])//中间严格小于边缘
				s1.pop();
		}
		s1.push(i);
		while(!s2.empty()&&h[s2.top()]<h[i])
		{//s2维护左面比h[i]高的位置
			dp[i]=min(dp[i],dp[s2.top()]+1);
			s2.pop();
		}
		if(!s2.empty())
		{
			dp[i]=min(dp[i],dp[s2.top()]+1);
			if(h[s2.top()]==h[i])//中间严格大于边缘
				s2.pop();
		}
		s2.push(i);
	}
//	for(int i=1;i<=n;i++)
//		printf("dp[%d]=%d\n",i,dp[i]);
	cout<<dp[n]<<endl;
	return 0;
}
/*
 *最小步数从1->n,应该是dp
 *好像单调队列优化不了?出队时候更新信息?
 *维护一个全部小于/大于起始点的队列
 *好难搞...不能是二分吧...还是数据结构维护区间最值?
 *真不能是暴力bfs吧...
 *原来使用单调栈维护单调性...我太菜了
羽根が白く光り 眩しく飛んで行く
心だけ乗せて欲しいのに

 */

