#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
struct edge
{
	int v,nex;
	double w;
} e[maxn<<1];
int head[maxn],cnt;
struct mess
{
	int o,a,b,k;
} ha[maxn<<1];
int c[maxn],grade[maxn];
inline void add(int u,int v,double w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
bool spfa(int x)//DFS优化
{
	vis[x]=1;
	for(int i=head[x];~i;i=e[i].next)
	{
		int v=e[i].v;
		if(dist[v]>dist[x]+e[i].w)
		{
			dist[v]=dist[x]+e[i].w;
			if(vis[v])//存在一点在一条路径上出现多次，存在负权环
				return 0;
			if(!spfa(v))//搜到了存在负权环
				return 0;
		}
	}
	vis[x]=0;
	return 1;//未找到负权环
}
bool check(int n,int s)
{//建一个不女装的差分系统,二分t来找负环
	memset(head,-1,sizeof(head));
	cnt=0;
	double delta=1e-5;
	for(int i=1;i<=s;i++)
	{
		if(mess[i].o==1)
		{//a未k倍杀b则a女装
			add()
		}
		else{//a成功k倍杀b则b女装

		}
	}
	return spfa();
}
double solve(int n,int s,int lim)//n个人,s个约束
{
	double l=0,r=lim,mid,ans=1e9,delta=1e-6;
	while(r-l<=delta)
	{
		mid=(l+r)/2;
		if(check(n,s))//没有负权环,t需减小
			r=mid;
		else
			ans=l=mid;//答案符合t增大,寻找更优解
	}
	return ans;
}
int main()
{
	int n,s,t,ope,a,b,k;
	scanf("%d%d%d",&n,&s,&t);
	double r=0;
	for(int i=1;i<=s;i++)
	{
		scanf("%d%d%d%d",&ha[i].o,&ha[i].a,&ha[i].b,&ha[i].k);
		if(ha[i].o==1)
			r=max(r,(double)ha[i].k);//保证最少有一个k-t不为负
	}
	for(int i=1;i<=t;i++)
		scanf("%d%d",&c[i],&grade[i]);
	double ans=solve(n,s,r);
	if(ans<1e9)
		printf("%lf\n",ans);
	else
		printf("-1\n");
	return 0;
}
