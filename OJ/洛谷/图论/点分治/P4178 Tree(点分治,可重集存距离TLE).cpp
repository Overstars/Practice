#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=40005;
struct edge
{
	int v,nex,w;
} e[maxn<<1];
int tot=0,head[maxn];
inline void add(int u,int v,int w)
{
	e[++tot].v=v;
	e[tot].w=w;
	e[tot].nex=head[u];
	head[u]=tot;
}
int n,k,root=0,sum=0;
ll siz[maxn],maxp[maxn];
bool vis[maxn];
void getrt(int x,int fa)
{
	siz[x]=1,maxp[x]=0;
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa||vis[v])
			continue;
		getrt(v,x);
		siz[x]+=siz[v];
		maxp[x]=max(maxp[x],siz[v]);
	}
	maxp[x]=max(maxp[x],sum-siz[x]);
	if(maxp[x]<maxp[root])
		root=x;
}
ll cnt,dist[maxn],tmp[maxn],ans=0;
void getdist(int x,int fa)
{
	tmp[++cnt]=dist[x];
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa||vis[v])
			continue;
		dist[v]=dist[x]+e[i].w;
		getdist(v,x);
	}
}
multiset<ll> QAQ;
void solve(int x)
{
	QAQ.insert(0);
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(vis[v])
			continue;
		cnt=0;
		dist[v]=e[i].w;
		getdist(v,x);
//		for(int j=1;j<=cnt;j++)
//			cout<<"tmp["<<j<<"]="<<tmp[j]<<endl;
		for(int j=1;j<=cnt;j++)
//			for(set<int>::iterator it=QAQ.begin();it!=QAQ.end();it++)
			for(auto it:QAQ)
				if(tmp[j]<=k)
				{
					if(it>k-tmp[j])
						break;
					else//jud+tmp<=k
					{
						ans++;
//						cout<<"tmp:"<<tmp[j]<<"+it:"<<it<<"<"<<k<<endl;
					}
//					cout<<"ans="<<ans<<",it="<<*it<<endl;
				}
		for(int j=1;j<=cnt;j++)
		{
			QAQ.insert(tmp[j]);
		}
	}
//	cout<<"*********"<<endl;
	while(!QAQ.empty())
	{
		int era=*QAQ.begin();
//		cout<<era<<"已被删除..."<<endl;
		QAQ.erase(era);
	}
}
void divide(int x)
{
//	cout<<"根节点为:"<<x<<endl;
	vis[x]=1;
	solve(x);//计算经过x节点的路径
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(vis[v])
			continue;
		maxp[root=0]=sum=siz[v];
		getrt(v,0);
		getrt(root,0);
		divide(root);
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	int u,v,w;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	cin>>k;
	maxp[0]=sum=n;
	getrt(1,0);
	getrt(root,0);
	divide(root);
	cout<<ans<<endl;
	return 0;
}
