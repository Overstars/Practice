#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=20005;
struct edge
{
	int v, no;
	edge(int v,int no):
		v(v),no(no){}
};
vector<edge> G[maxn];
int dfn[maxn],low[maxn],tot,cnt=0,flag=0;
bool bri[maxn];
pair<int,int> ans[maxn];
bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.first<b.first)
		return 1;
	if(a.first==b.first)
		return a.second<b.second;
	return 0;
}
bool stcmp(const edge &a,const edge &b)
{
	return a.v<b.v;
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++tot;
	bool vis=0;//�����ر�Ҫ����,��ʾ����ڵ㻹û�б������ѵ�
	for(int i=0;i<G[x].size();i++)
	{
		int v=G[x][i].v,no=G[x][i].no;
		if(!dfn[v])
		{
			tarjan(v,x);
			if(low[v]>dfn[x])//�������Ǵ���
			{
				bri[no]=1;
//				pair<int,int> tem;
//				tem.first=x,tem.second=v;
//				ans[flag++]=tem;
			}
			low[x]=min(low[x],low[v]);
		}
		else if(dfn[x]>dfn[v])
		{
			if(v==fa&&!vis)
				vis=1;//���˵�һ�Σ�ÿ�λص����ڵ㶼�ø��ڵ��ֵ���µ�ǰ����ֵ
			else//֮ǰ��v!=faʱ���ø��ڵ�ֵ���¸õ��ֵ
				low[x]=min(low[x],dfn[v]);
		}
	}
}
//#define DEBUG
int main()
{
	#ifdef DEBUG
	freopen("P1656.in","r",stdin);
	#endif // DEBUG
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(edge(v,++cnt));//����ͼ
		G[v].push_back(edge(u,++cnt));
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i,i);
	for(int i=1;i<=n;i++)//�ߵ��������
	{
		sort(G[i].begin(),G[i].end(),stcmp);
		for(int j=0;j<G[i].size();j++)//Ҫ�ȶ�ÿһ��vector���������
			if(bri[G[i][j].no])
				cout<<i<<' '<<G[i][j].v<<endl;
	}
//	sort(ans,ans+flag,cmp);
//	for(int i=0;i<flag;i++)
//		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}
/*
int n,m,x,y,index_,dfn[maxn],low[maxn],ans,a;//index_����ǰ��ʱ���
vector<int>G[maxn];//��ߵ����ݽṹ���ڽӱ�
struct Edge{int from,to;}edge[maxn];//�𰸵ıߣ������Ҫ����
bool cmp(const Edge a,const Edge b){if(a.from!=b.from)return a.from<b.from;return a.to<b.to;}//�𰸱ߵıȽϺ���
inline void add_edge(int x,int y){edge[ans].from=min(x,y);edge[ans].to=max(x,y);ans++;}//�ڴ��м���һ����
void dfs(int cur,int fa)//cur�ǵ�ǰ�ڵ㣬fa�����ĸ���
{
    int child;
    dfn[cur]=++index_;//���㵱ǰ�ڵ��ʱ���
    low[cur]=dfn[cur];//��ǰ���Է��ʵ�������ʱ����϶����Լ���ʱ���
    for(int i=0;i<G[cur].size();i++)//����cur�����г���
    {
        child=G[cur][i];
        if(dfn[child]&&child!=fa)
			low[cur]=min(low[cur],dfn[child]);//������ʵ��˲��Ǹ��׽ڵ�Ľڵ㣬����low��ֵ
        if(!dfn[child])//�������ڵ�֮ǰû�б����ʹ�
        {
            dfs(child,cur);//����һ��dfs����
            if(dfn[cur]<low[child])add_edge(cur,child);//��������������ڴ������м���������
            low[cur]=min(low[cur],low[child]);//����low��ֵ
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)scanf("%d%d",&x,&y),G[x].push_back(y),G[y].push_back(x);
    for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,i);//ͼ���ܲ���ͨ����ʼʱfa��i�����������
    sort(edge,edge+ans,cmp);//���������Ÿ���
    for(int i=0;i<ans;i++)printf("%d %d\n",edge[i].from,edge[i].to);//���
    return 0;
}
*/
