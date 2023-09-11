#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct edge
{
	int u,v,w;
	edge(int u,int v,int w):
		u(u),v(v),w(w){}
};
vector<edge> E;
bool cmp(const edge &x,const edge &y)
{
	return x.w<y.w;
}
bool mp[maxn];
int main()
{
	int n,m,k,u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		E.push_back(edge(u,v,w));
	}
	sort(E.begin(),E.end(),cmp);
	for(int i=0;i<k;i++)
	{
		cin>>u;
		mp[u]=1;//仓库
	}
	bool flag=1;
	for(auto &e:E)
	{
		if(mp[e.u]!=mp[e.v])
		{
			cout<<e.w<<endl;
			flag=0;
			break;
		}
	}
	if(flag)
		cout<<-1<<endl;
	return 0;
}
