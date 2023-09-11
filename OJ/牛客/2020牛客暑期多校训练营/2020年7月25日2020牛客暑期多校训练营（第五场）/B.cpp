#include<bits/stdc++.h>
#define RG register
#define il inline
#define iter iterator
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
const int N=4000005,maxn=1e5+5;
inline int gi(){
	RG int str=0;RG char ch=getchar();
	while(ch>'9' || ch<'0')ch=getchar();
	while(ch>='0' && ch<='9')str=(str<<1)+(str<<3)+ch-48,ch=getchar();
	return str;
}
int n,rt=0,bin[30],sz[N],ls[N],rs[N],totnode=0;
ll ans=0;

il void ins(int &x,int v,int d){
	if(!x)x=++totnode;
	if(d==-1){sz[x]=1;return ;}
	if(bin[d]&v)ins(rs[x],v,d-1);
	else ins(ls[x],v,d-1);
	sz[x]=sz[ls[x]]+sz[rs[x]];
}

il int qry(int x,int v,int d){
	if(d==-1)return 0;
	if(v&bin[d]){
		if(rs[x])return qry(rs[x],v,d-1);
		return qry(ls[x],v,d-1)+bin[d];
	}
	else{
		if(ls[x])return qry(ls[x],v,d-1);
		return qry(rs[x],v,d-1)+bin[d];
	}
}

il int merge(int x,int y,int d,int val,int sd){
	if(d==-1)return qry(y,val,sd);
	int ret=1<<30;
	if(ls[x])ret=min(ret,merge(ls[x],y,d-1,val,sd));
	if(rs[x])ret=min(ret,merge(rs[x],y,d-1,val+bin[d],sd));
	return ret;
}

il void dfs(int x,int d){
	if(d==-1)return ;
	if(ls[x])dfs(ls[x],d-1);
	if(rs[x])dfs(rs[x],d-1);
	if(!ls[x] || !rs[x])return ;
	int l=ls[x],r=rs[x];
	if(sz[l]>sz[r])swap(l,r);
	ans+=merge(l,r,d-1,0,d-1)+bin[d];
}
struct edge
{
	int v,w;
	edge(int v=0,int w=0):
		v(v),w(w){}
};
vector<edge>G[maxn];
int val[maxn];
void get(int x,int fa)
{
	for(auto &e:G[x])
	{
		if(e.v==fa)
			continue;
		val[e.v]=val[x]^e.w;
		get(e.v,x);
	}
}
void work()
{
	cin>>n;
	for(int i=1,u,v,w;i<n;i++)
	{
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	get(0,0);
	for(int i=1;i<=n;i++)
		ins(rt,val[i],30);
	dfs(rt,30);
	cout<<ans<<endl;
}
int main()
{
	bin[0]=1;for(int i=1;i<=30;i++)
		bin[i]=bin[i-1]<<1;
	work();
	return 0;
}


