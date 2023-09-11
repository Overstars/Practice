#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
int cnt,head[maxn];
struct edge
{
	int v,nex;
} e[maxn<<1];
inline add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
ll lef=0;
ll dfs(int x,int fa,int flag)//统计与x节点同一
{
	if(flag)
		lef++;
	for(int i=head[x];~i;i=e[i].nex)
	{
		if(e[i].v!=fa)
			dfs(e[i].v,x,1-flag);
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	ll n,u,v;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	dfs(1,1,1);
	cout<<(n-lef-1)*(lef-1)<<endl;
	return 0;
}
/*
 *该题不能加新节点
 *观察得出答案:(左-1)*(右-1)
 */

