#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f,MAXN=30;
int father[MAXN];
struct edge
{
	int u,v,w;
} e[MAXN*MAXN];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
void init(int n)
{
	for(int i=1;i<=n;i++)
		father[i]=i;
}
int findfa(int x)
{
	if(father[x]!=x)
		father[x]=findfa(father[x]);
	return father[x];
}
int Merge(int a,int b)
{
	int x=findfa(a),y=findfa(b);
	if(x==y)
		return 0;
	else if(x<y)
		father[y]=x;
	else
		father[x]=y;
	return 1;
}
int kruskal(int n,int m)//
{
	int ans=0;
	for(int i=0;i<m;i++)
	{
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
	int n,k,cnt=0;
	char ch,chpre;
	while(cin>>n&&n){
		init(n);
		cnt=0;
		for(int i=1;i<n;i++)
		{
			cin>>chpre>>k;
			int x=chpre-'A'+1,y;
			for(int j=0;j<k;j++)
			{
				cin>>ch>>e[cnt].w;
				y=ch-'A'+1;
				e[cnt].u=x,e[cnt].v=y;
				cnt++;
			}
		}
		sort(e,e+cnt,cmp);
		cout<<kruskal(n,cnt)<<endl;
	}
	return 0;
}
