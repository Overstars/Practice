#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f,MAXN=1051;
struct edge
{
	int v,nex;
	ll w;
} e[MAXN*MAXN];
int cnt,head[MAXN],num[MAXN];
ll dist[MAXN];
bool vis[MAXN];
inline void add(int u,int v,ll w)//链式前向星存图,无向则双向添加
{
	e[++cnt].v=v;//边的结尾节点
	e[cnt].w=w;
	e[cnt].nex=head[u];//去找以u为起始的上一个节点(相当于链表,起始为-1)
	head[u]=cnt;//保存该边(最后的边)在e[i]中的编号
}
bool SPFA(int n,int x)//节点数量n,起点编号x
{
	memset(dist,inf,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	dist[x]=0;//该题起点任意
	num[x]++;//入队次数++
	queue<int> QAQ;
	QAQ.push(x);
	while(!QAQ.empty())
	{
//		cout<<"????"<<endl;
		int now=QAQ.front();
		QAQ.pop();
		vis[now]=0;//从队列中取出
		for(int i=head[now];~i;i=e[i].nex)
		{//遍历以now开头的所有边,尝试以x->now->to松弛x->to
			int to=e[i].v;//尝试松弛x->to的当前距离
//			printf("i=%d,nex=%d\n",i,e[i].nex);
//			printf("now=%d,to=%d\n",now,to);
			if(dist[to]>dist[now]+e[i].w)
			{
				dist[to]=dist[now]+e[i].w;//成功用x->now->to松弛x->to
				if(!vis[to])//x->to被成功松弛且to不在队列
				{
					vis[to]=1;//标记to加入队列
					QAQ.push(to);
					if(++num[to]>n)//to加入队列次数++
						return 1;//有负权回路,无法求最短路径
				}
			}
		}
	}
//	cout<<"跑完"<<endl;
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
//	freopen("P4878.in","r",stdin);
//	freopen("P4878(1).in","r",stdin);
	memset(head,-1,sizeof(head));
	cnt=0;
	int n,l,d,u,v;
	ll di;
//	cin>>n>>l>>d;
	scanf("%d%d%d",&n,&l,&d);
	for(register int i=1;i<=l;i++)
	{
		scanf("%d%d%lld",&u,&v,&di);
//		cin>>u>>v>>di;
		add(u,v,di);
//		cout<<"!!!"<<endl;
	}
	for(register int i=1;i<=d;i++)
	{
//		cin>>u>>v>>di;
		scanf("%d%d%lld",&u,&v,&di);
		add(v,u,-di);
	}
	for(int i=1;i<n;i++)
		add(i+1,i,0);//隐藏条件,距离大于等于0,高->低建边
	for(int i=1;i<=n;i++)
		add(0,i,0);//加单向边,找出在不连通情况下是否存在负权环
	if(SPFA(n,0))
		printf("-1\n");
	else{
		if(SPFA(n,1))
			printf("-1\n");
		else if(dist[n]>=inf)//没写特判inf,不能只是等于……
			printf("-2\n");
		else
			printf("%lld\n",dist[n]);
	}
//	for(int i=1;i<=n;i++)
//		cout<<"dist["<<i<<"]="<<dist[i]<<endl;
	return 0;
}
