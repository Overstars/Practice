#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int maxl=31;
int lg[maxn],gene[maxn][maxl],depth[maxn],cnt=0;
struct edge
{
	int u,v,nex;
//	edge(){u=0,v=0,nex=0;}
	edge(int u=0,int v=0,int nex=-1):
		u(u),v(v),nex(nex){}
} G[maxn<<1];
int head[maxn];
void add(int u,int v)
{
	G[++cnt].u=u;
	G[cnt].v=v;
	G[cnt].nex=head[u];
	head[u]=cnt;
}
void dfs(int x,int fa)
{
	depth[x]=depth[fa]+1;
	gene[x][0]=fa;
	for(int i=1;(1<<i)<=depth[x];i++)
		gene[x][i]=gene[gene[x][i-1]][i-1];
	for(int i=head[x];~i;i=G[i].nex)
		if(G[i].v!=fa)
			dfs(G[i].v,x);
}
int lca(int x,int y)
{
	if(depth[x]<depth[y])
		swap(x,y);
	while(depth[x]>depth[y])
		x=gene[x][lg[depth[x]-depth[y]-1]];
	if(x==y)
		return x;
	for(int i=lg[depth[x]];i>=0;i--)
		if(gene[x][i]!=gene[y][i])
		{
			x=gene[x][i];
			y=gene[y][i];
		}
	return gene[x][0];
}
int init(int s,int n)
{
	memset(gene,0,sizeof(gene));
	for(int i=1;i<=n;i++)//lg����Ӧ����ôд
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
	depth[s]=1;
	dfs(s,0);
}
int power[maxn];//�ڵ㵽���ĸ��ڵ�ıߵ�
int ans[maxn],id[maxn];
void dfs(int u)
{
	for(int i=head[u];~i;i=G[i].nex)
		if(G[i].v!=gene[u][0])
		{
//			cout<<"HAHAH"<<endl;
			dfs(G[i].v);
			power[u]+=power[G[i].v];//���ڵ�ȨֵΪ�ӽڵ�Ȩֵ֮��
		}
	ans[id[u]]=power[u];//�ڵ㵽���׵ı߾�������
}
int main()
{
	memset(head,-1,sizeof(head));
	int n,x,y,k;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		add(x,y);//δָ����,������ͼ
		add(y,x);//�����п����Ѳ���
	}
	init(1,n);
	int len=2*n-1;
	for(int i=1;i<len;i+=2)//��ÿ���߱��,�Ե����
		if(depth[G[i].u]>depth[G[i].v])
			id[G[i].u]=(i+1)/2;//�ߵ�ͷΪu(u����)
		else//id[u]:u���������ȵı߱��Ϊid[u],��ż�Ϊ�ñ�����˳��
			id[G[i].v]=(i+1)/2;
	cin>>k;
	while(k--)
	{
		cin>>x>>y;
		int ances=lca(x,y);
		power[x]++;
		power[y]++;
		power[ances]-=2;
	}
	dfs(1);
//	for(int i=1;i<n;i++)
//	{
//		cout<<"power["<<i<<"]="<<power[i]<<endl;
//	}
	for(int i=1;i<n;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}
