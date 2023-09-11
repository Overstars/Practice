#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f,maxn=100005;
int read()//快读挂
{
    int x=0,f=1;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return x*f;
}
struct node
{
	int v,next;
	ll w;
} e[maxn<<2];
ll dist[maxn];
int cnt,head[maxn],num[maxn];
bool vis[maxn];
inline void add(int u,int v,ll w)//链式前向星存图,无向则双向添加
{
	e[++cnt].v=v;//边的结尾节点
	e[cnt].w=w;
	e[cnt].next=head[u];//去找以u为起始的上一个节点(相当于链表,起始为-1)
	head[u]=cnt;//保存该边(最后的边)在e[i]中的编号
}
bool SPFA(int n,int x)//节点数量n,起点编号x
{
//	memset(dist,inf,sizeof(dist));
//	memset(vis,0,sizeof(vis));
//	memset(num,0,sizeof(num));
//	fill(dist,dist+maxn,-inf);
	dist[x]=0;//该题起点任意
	num[x]++;//入队次数++
	queue<int> QAQ;
	QAQ.push(x);
	while(!QAQ.empty())
	{
		int now=QAQ.front();
		QAQ.pop();
		vis[now]=0;//从队列中取出
		for(int i=head[now];~i;i=e[i].next)
		{//遍历以now开头的所有边,尝试以x->now->to松弛x->to
			int to=e[i].v;//尝试松弛x->to的当前距离
//			printf("%d->%d,dis[%d]=%d\n",now,to,to,dist[to]);
			if(dist[to]<dist[now]+e[i].w)
			{
				dist[to]=dist[now]+e[i].w;//成功用x->now->to松弛x->to
				if(!vis[to])//x->to被成功松弛且to不在队列
				{
					if(++num[to]>n)
						return 1;//有负权回路,无法求最短路径
					vis[to]=1;//标记to加入队列
					QAQ.push(to);
				}
			}
		}
	}
	return 0;
}
int main()
{
//	freopen("P3275 [SCOI2011]糖果(差分约束).in","r",stdin);
//	memset(head,-1,sizeof(head));
	int n,k,ope,a,b;
//	scanf("%d%d",&n,&k);
	n=read(),k=read();
	fill(head,head+n+1,-1);
	while(k--)
	{
//		scanf("%d%d%d",&ope,&a,&b);
		ope=read(),a=read(),b=read();
		if(ope==1)
		{
			add(b,a,0);
			add(a,b,0);
		}
		else if(ope==2)
		{
			add(a,b,1);
		}
		else if(ope==3)
		{
			add(b,a,0);
		}
		else if(ope==4)
		{
			add(b,a,1);
		}
		else{
			add(a,b,0);
		}
		if(ope%2==0&&a==b)
		{
			printf("-1\n");
			exit(0);
		}
	}
	for(int i=n;i>0;i--)//超级源点,卡SPFA,倒叙连边
		add(0,i,1);//限制,每个节点至少有一个糖果
	if(SPFA(n,0))
		printf("-1\n");
	else{
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans+=dist[i];//求最长路
		printf("%lld\n",ans);
	}
	return 0;
}
