#include<iostream>
#include<cstdio>
#include<algorithm>//G++��WA,C++�ͻ�AC
#include<cstring>//Ҫ��n�����ݱ�����������
#include<cmath>//���˻���ѧһ��prim��
//ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�O(n)
//�� ��V-u��Ѱ������Ľڵ�t ��ʹ�����ȶ���,ʱ�临�Ӷ�logn,ִ��n��
//�� ���ݼ����t�ڵ����lowcost��closest �ɲ����ڽӱ�洢,ÿ��ֻ����ڽӱ�,������Ϊ����E,���ʱ�临�Ӷ�logn,ÿ�θ��¸��Ӷ�O(Elogn)
//
using namespace std;
const int inf=0x3f3f3f3f,MAXN=105;
struct Node
{
	double x,y,z,r;
} node[MAXN];
bool tree[MAXN];//true���Ѽ���tree
int closest[MAXN];//�����i���ڵ�ʱ����������ڵ�
double dis[MAXN][MAXN],lowcost[MAXN];//��Ȩ��,�����i���ڵ��������Ͻڵ�ľ���
double prim(int n,int u0,double dis[MAXN][MAXN])
{
	memset(tree,0,sizeof(tree));
	tree[u0]=1;//������
	int i,j;
	double ans=0;
	for(i=1;i<=n;i++)//�� ��ʼ��,
	{
		if(i!=u0)
		{
			lowcost[i]=dis[u0][i];
			closest[i]=u0;//һ��ʼֻ��u0
		}
		else
			lowcost[u0]=0;
	}
	for(i=1;i<=n;i++)//�� ÿ��ѡ����һ������Ľڵ�
	{
		double tempdist=inf;
		int t=u0;
		for(j=1;j<=n;j++)//�� ��V-u��Ѱ������Ľڵ�t
		{
			if(!tree[j]&&lowcost[j]<tempdist)
			{
				t=j;
				tempdist=lowcost[j];
			}
		}
		if(t==u0)
			break;//�Ҳ���t,û�пɼ���Ľڵ�,����
		tree[t]=1;//�ҵ��˾ͼ���tree
		for(j=1;j<=n;j++) //�� ���ݼ����t�ڵ����lowcost��closest
		{
			if(!tree[j]&&dis[t][j]<lowcost[j])
			{
				lowcost[j]=dis[t][j];
				closest[j]=t;
			}
		}
	}
	for(i=1;i<=n;i++)
		ans+=lowcost[i];
	return ans;
}
int main()
{
	int n,i,j;
	while(cin>>n&&n){
		for(i=1;i<=n;i++)
			cin>>node[i].x>>node[i].y>>node[i].z>>node[i].r;
		for(i=1;i<=n;i++)//�����Ȩ��
			for(j=1;j<=n;j++){
				dis[i][j]=sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y)+(node[i].z-node[j].z)*(node[i].z-node[j].z))-node[i].r-node[j].r;
				if(dis[i][j]<0)
					dis[i][j]=0;//�Ѿ�����,ȨֵΪ��
				dis[j][i]=dis[i][j];
			}
		printf("%.3lf\n",prim(n,1,dis));
	}
	return 0;
}
