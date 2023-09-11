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
inline int cal(int x,int dis)
{
	cnt=0,dist[x]=dis;//到父节点距离设好
	getdist(x,0);//这里的父节点随便设...
	sort(tmp+1,tmp+cnt+1);
	int ret=0,l=1,r=cnt;
	while(l<r)//暴力统计,但同一棵子树上的路径也会统计进去
	{
		if(tmp[l]+tmp[r]<=k)
			ret+=r-l,l++;
		else
			r--;
	}
	return ret;
}
void divide(int x)
{
	vis[x]=1;
	ans+=cal(x,0);//计算经过x节点的路径(以x为根的子树,带折返)
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(vis[v])
			continue;//计算以v为根的子树上的节点到x的距离(不形成跨过x的路径)
		ans-=cal(v,e[i].w);//去掉子树上折返的路线,多减去的子树的子树(该子树上组合出来的符合条件的路径)
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
