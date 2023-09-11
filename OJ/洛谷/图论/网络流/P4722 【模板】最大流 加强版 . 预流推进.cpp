#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
const int INF=INT_MAX;
const int maxn=10005;
const int maxm=1000005;
typedef long long ll;
struct HLPP
{
	struct edge
	{
		int to,flow,next;
		edge(int to,int flow,int next):
			to(to),flow(flow),next(next){}
	};
	vector<edge> edges[maxn];//邻接表存图
	int n,m,s,t;//节点,边数,源点,汇点
	int head[maxn],height[maxn];
	struct cmp
	{
		int line bool operator()(int a,int b) const
		{
			return height[a]<height[b];//优先队列
		}
	};
	queue<int> q;
	priority_queue<int,vector<int>,cmp> pq;
	void init(int n)
	{
		this->n=n;
		edges.empty();
		memset(head,-1,sizeof(head));
	}
	inline void add(int from,int to,int flow=0)
	{
		edges[from].push_back(edge(to,flow,edges[to].size()));
		edges[to].push_back(edge(from,0,edges[from].size()-1));
	}

};
inline int read()
{
    int f=0,fu=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')fu=-1;c=getchar();}
    while(c>='0'&&c<='9'){f=(f<<3)+(f<<1)+c-48;c=getchar();}
    return f*fu;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	return 0;
}

