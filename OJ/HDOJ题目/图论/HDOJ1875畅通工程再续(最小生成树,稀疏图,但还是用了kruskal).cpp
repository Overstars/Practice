#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>//这题要尝试所有边嘞,稀疏图啊
using namespace std;
const int inf=0x3f3f3f3f,maxn=105;
struct Node
{
	int x,y;
} node[maxn];
struct edge
{
	int u,v;
	double w;
} e[maxn*maxn];
int father[maxn];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
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
	if(x<y)
		father[y]=x;
	else
		father[x]=y;
	return 1;
}
double kruskal(int n,int m)
{
	double ans=0;
	for(int i=0;i<m;i++)
	{
		if(e[i].w>=10&&e[i].w<=1000&&Merge(e[i].u,e[i].v))
		{
			ans+=e[i].w;
			n--;
			if(n==1)
				return ans;
		}
	}
	return -1;
}
int main()
{
	int t,c,x,y;
	cin>>t;
	while(t--){
		cin>>c;
		for(int i=1;i<=c;i++)
			cin>>node[i].x>>node[i].y;
		int cnt=0;
		for(int i=1;i<=c;i++)
			for(int j=1;j<i;j++)
			{
				double dist=sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y));
				e[cnt].u=i;
				e[cnt].v=j;
				e[cnt++].w=(dist<10||dist>1000)?inf:dist;
			}
		for(int i=1;i<=c;i++)
			father[i]=i;
		sort(e,e+cnt,cmp);
		double ans=0;
		if((ans=kruskal(c,cnt))==-1)
			cout<<"oh!"<<endl;
		else
			printf("%.1lf\n",ans*100);
	}
	return 0;
}
