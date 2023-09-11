
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f,MAXN=52;
int father[MAXN];
struct edge
{
	int u,v,w;
} e[MAXN*MAXN];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
void initial(int n)
{
	for(int i=1;i<=n;i++)
		father[i]=i;
}
int findfa(int x)
{
	if(x!=father[x])
		father[x]=findfa(father[x]);
	return father[x];
}
int Merge(int a,int b)
{
	int x=findfa(a),y=findfa(b);
	if(x==y)
		return 0;
	if(x>y)
		father[x]=y;
	else
		father[y]=x;
	return 1;
}
int kruskal(int n,int m)
{
	int ans=0;
	for(int i=0;i<m;i++)
	{
//		printf("µÚ%dÌõ±ß.\n",i+1);
		if(Merge(e[i].u,e[i].v))
		{
			ans+=e[i].w;
			n--;
			if(n==1)
				return ans;
		}
	}
	return 0;
}
int main()
{
	int n,m;
	while(cin>>n>>m){
		if(n==0)
			break;
		initial(n);
		for(int i=0;i<m;i++)
		{
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
//		printf("I am here.\n");
		sort(e,e+m,cmp);
		cout<<kruskal(n,m)<<endl;
	}
	return 0;
}
