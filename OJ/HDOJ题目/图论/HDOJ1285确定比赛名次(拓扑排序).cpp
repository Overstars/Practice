#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=505;
int Top[maxn],Node[maxn],n,m;
vector<int> G[maxn];
void topsort(void)
{
	priority_queue<int,vector<int>,greater<int> > QAQ;//С����
	for(int i=1;i<=n;i++)
		if(G[i][0]==0)//���Ϊ0
			QAQ.push(i);
	int cnt=0;
	while(!QAQ.empty())
	{
		int x=QAQ.top();
		Top[x]=++cnt;//��¼��������,x�ڵ�Ĵ���
		QAQ.pop();
		for(int i=1;i<G[x].size();i++)
		{
			if(--G[G[x][i]][0]==0)//ȥ��x�ڵ��,��һ�ڵ���ȱ�Ϊ0
				QAQ.push(G[x][i]);
		}
//		cout<<"IN QUEUE"<<endl;
	}
	if(cnt!=n)//�в���ͨ��
		return;
	for(int i=1;i<=n;i++)
	{
		if(G[i][0])//�л�ͼ
			return;
	}
	for(int i=1;i<=n;i++)
		Node[Top[i]]=i;//������,Node[i]=x:��i��Ϊx
	for(int i=1;i<=n;i++)
		printf("%d%c",Node[i],i<n?' ':'\n');
	return;
}
int main()
{
	while(cin>>n>>m)//n������,m������
	{
		for(int i=1;i<=n;i++)//��ʼ��
		{
			G[i].clear();
			G[i].push_back(0);//G[i][0]��¼���
		}
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v][0]++;//v������+1
		}
		topsort();
	}
	return 0;
}
