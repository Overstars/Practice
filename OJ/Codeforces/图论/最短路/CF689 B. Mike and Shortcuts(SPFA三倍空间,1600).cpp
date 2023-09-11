#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct node
{
	int v,w,nex;
} e[maxn*3];
int cnt=0,dist[maxn],head[maxn],num[maxn];
bool vis[maxn];
void add(int u,int v,int w)//链式前向星存图,无向则双向添加
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
	vis[x]=1;
	num[x]++;//入队次数++
	queue<int> QAQ;
	QAQ.push(x);
	while(!QAQ.empty())
	{
		int now=QAQ.front();
//		printf("now=%d\n",now);
		QAQ.pop();
		vis[now]=0;//从队列中取出
		for(int i=head[now];i!=-1;i=e[i].nex)
		{//遍历以now开头的所有边,尝试以x->now->to松弛x->to
			int to=e[i].v;//尝试松弛x->to的当前距离
			if(dist[to]>dist[now]+e[i].w)
			{
				dist[to]=dist[now]+e[i].w;//成功用x->now->to松弛x->to
				if(!vis[to])//x->to被成功松弛且to不在队列
				{
					vis[to]=1;//标记to加入队列
					QAQ.push(to);
					num[to]++;//to加入队列次数++
					if(num[to]>n)
						return 1;//有负权回路,无法求最短路径
				}
			}
		}
	}
	return 0;
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	memset(head,-1,sizeof(head));
	int n;
	cin>>n;
//	for(int i=1;i<=n;i++)
//		cin>>a[i];//从i到a[i]消耗1能量
	for(int i=1,tmp;i<=n;i++)
	{
		cin>>tmp;
		add(i,tmp,1);
		if(i<n)
		{
			add(i,i+1,1);
			add(i+1,i,1);
		}
	}
	SPFA(n,1);
	for(int i=1;i<=n;i++)
		cout<<dist[i]<<' ';
	return 0;
}


