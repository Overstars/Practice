#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=50005;
struct edge
{
	int v,nex;//��ʽǰ����
} e[maxn];
int head[maxn];//head[u]��ʾ��uΪ���ıߵ�����
int dfn[maxn],low[maxn],stk[maxn],cnt,tot,Index,ans;
bool vis[maxn];
void add(int u,int v)
{
	e[++cnt].nex=head[u];
	e[cnt].v=v;
	head[u]=cnt;
}
void tarjan(int x)//����x�Žڵ�
{//dfn[x]��¼��ǰ����ʱ��,low[x]��¼����ǿ��ͨ��ͼ����Сʱ���
	dfn[x]=low[x]=++tot;//�µ�ĳ�ʼ��
	stk[++Index]=x;//��ջ
	vis[x]=1;//��ʾx�ڵ���ջ��
	for(int i=head[x];i!=-1;i=e[i].nex)//x�������쵽v�ڵ�(e[i].v)
	{//������˳�����ߵ�˳���෴
		if(!dfn[e[i].v])//v֮ǰδ���ʹ�
		{
			tarjan(e[i].v);//��������
			low[x]=min(low[x],low[e[i].v]);//x�Ƿ�Ϊv���ӽڵ�
		}
		else if(vis[e[i].v])//v��ջ��
		{
			low[x]=min(low[x],dfn[e[i].v]);//v�Ƿ�Ϊx�ĸ�С����
		}//��v�������Ҳ���ջ��,ֱ���Թ�
	}
	if(low[x]==dfn[x])//x������ǿ��ͨ�������������С��
	{
		int tem=0;
		do{
//			printf("%d ",stk[Index]);
			vis[stk[Index]]=0;
			Index--;
			tem++;
		}while(stk[Index+1]!=x);//��ջ
		if(tem>1)//��ǿ��ͨͼ�ڵ����1
			ans++;
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])//iû�б�����(ͼ����ͨ)
			tarjan(i);
	cout<<ans<<endl;
	return 0;
}
