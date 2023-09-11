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
const int maxn=105;
//#define DEBUG
int fa[maxn];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
		fa[b]=a;
	else
		fa[a]=b;
	return 1;
}
struct node
{
	int x,y;
} mp[maxn];
double dis(int a,int b)
{
	int xx=abs(mp[a].x-mp[b].x),yy=abs(mp[a].y-mp[b].y);
	return sqrt((double)xx*xx+(double)yy*yy);
}
struct edge
{
	int u,v;
	double w;
	edge(int u,int v,double w):
		u(u),v(v),w(w){}
};
bool cmp(const edge&a,const edge&b)
{
	return a.w<b.w;
}
double sol(int n,int x)//跳过x节点
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	vector<edge>G;
	for(int i=1;i<=n;i++)
	{
		if(i==x)
			continue;
		for(int j=i+1;j<=n;j++)
		{
			if(j!=x)
				G.push_back(edge(i,j,dis(i,j)));
		}
	}
	sort(G.begin(),G.end(),cmp);
	double ret=0;
	for(int i=0;i<G.size();i++)
	{
		edge &e=G[i];
		if(Merge(e.u,e.v))
		{
			n--;
			ret+=e.w;
			if(n==2)
				return ret;
		}
	}
	return 0;
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
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&mp[i].x,&mp[i].y);
		double ans=100000;
		for(int i=1;i<=n;i++)
			ans=min(ans,sol(n,i));
		printf("%.2f\n",ans);
	}
	return 0;
}
