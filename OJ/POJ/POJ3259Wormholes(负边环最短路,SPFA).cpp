#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//�������,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f,MAXN=5051;
struct node
{
	int v,w,next;
} e[MAXN];
int cnt,dist[MAXN],head[MAXN],num[MAXN];
bool vis[MAXN];
void add(int u,int v,int w)//��ʽǰ���Ǵ�ͼ,���������˫��
{
	e[cnt].v=v;//�ߵĽ�β�ڵ�
	e[cnt].w=w;
	e[cnt].next=head[u];//ȥ����uΪ��ʼ����һ���ڵ�(�൱������,��ʼΪ-1)
	head[u]=cnt++;//����ñ�(���ı�)��e[i]�еı��
}
bool SPFA(int n,int x)//�ڵ�����n,�����x
{
	memset(dist,inf,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	dist[x]=0;//�����������
	num[x]++;
	queue<int> QAQ;
	QAQ.push(x);
	while(!QAQ.empty())
	{
		int now=QAQ.front();
		QAQ.pop();
		vis[now]=0;//�Ӷ�����ȡ��
		for(int i=head[now];i!=-1;i=e[i].next)//������now��ͷ�����б�,������x->now->to�ɳ�x->to
		{
			int to=e[i].v;//�����ɳ�x->to�ĵ�ǰ����
			if(dist[to]>dist[now]+e[i].w)
			{
				dist[to]=dist[now]+e[i].w;//�ɹ���x->now->to�ɳ�x->to
				if(!vis[to])//x->to���ɹ��ɳ���to���ڶ���
				{
					vis[to]=1;//���to�������
					QAQ.push(to);
					num[to]++;//to������д���++
					if(num[to]>n)
						return 1;//�и�Ȩ��·,�޷������·��
				}
			}
		}
	}
	return 0;
}
int main()
{
	//����:�Ƿ����һ��Ȩֵ֮��Ϊ���Ļ�
	int t;
	cin>>t;
	while(t--)
	{
		cnt=0;
		int n,m,w;//n��,m����,w����
		scanf("%d%d%d",&n,&m,&w);
		memset(head,-1,sizeof(head));
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
			add(b,a,c);//������˫���
		}
		for(int i=0;i<w;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,-c);//�����ǵ����
		}
		cout<< (SPFA(n,1)?"YES":"NO") <<endl;
	}
	return 0;
}
