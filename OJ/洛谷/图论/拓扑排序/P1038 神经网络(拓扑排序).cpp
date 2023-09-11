#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
struct edge
{
	int u,v,w,nex;
} e[maxn<<1];
struct node
{
	int sta,u;//状态与阈值
	node()
	{
		sta=u=0;
	}
} a[maxn];
int head[maxn],cnt,pluse[maxn],topo[maxn],into[maxn],deg[maxn];
void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
bool topsort(int n)
{
	queue<int> QAQ;
	for(int i=1;i<=n;i++)
		if(a[i].sta>0)
		{
			pluse[i]=a[i].sta;
			QAQ.push(i);
		}
	int tot=0;
	while(!QAQ.empty())
	{
		int x=QAQ.front();
		topo[x]=++tot;
		QAQ.pop();
		for(int i=head[x];~i;i=e[i].nex)
		{
			int v=e[i].v;
			pluse[v]+=e[i].w*pluse[x];
			if(--into[v]==0)
			{
				pluse[v]-=a[v].u;//阈值
				if(pluse[v]>0)
					QAQ.push(v);
			}
		}
	}
	if(tot==n)
		return 1;
	return 0;
}
bool vis[maxn];
int main()
{
//	freopen("P1038_5.in","r",stdin);
	memset(head,-1,sizeof(head));
	int n,p;//n点,p边
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].sta>>a[i].u;
		pluse[i]=a[i].sta;
	}
	for(int i=1;i<=p;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		into[v]++;
		deg[u]++;//出度
	}
	topsort(n);
	bool flag=0;
	for(int i=1;i<=n;i++)
		if(pluse[i]>0&&deg[i]==0)
		{
			flag=1;
			cout<<i<<' '<<pluse[i]<<endl;
		}
	if(!flag)
		cout<<"NULL\n";
	return 0;
}
