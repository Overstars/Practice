#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
//ʱ�临�Ӷ�O(m*logm + m*logn)//��m����sort+����m����*���鼯�ϲ�(·��ѹ���Ż����β���O(log*n))
//�����m����Ժܴ�,�ʺϴ���������ٵ�ͼ
const int inf=0x3f3f3f3f;
const int MAXN=5005;//�Դ��ڽڵ���
int father[MAXN];//���鼯�Ż���¼��������
struct edge
{
	int u,v,w;//u,vΪ���ӵĽڵ�,wΪ��Ȩ
} e[MAXN*MAXN];
bool cmp(edge x,edge y)
{
	return x.w<y.w;//��Ȩ��С��������
}
void init(int n)
{
	for(int i=1;i<=n;i++)
		father[i]=i;
}
int findfa(int x)//�ҽڵ�x����
{
	if(x!=father[x])
		father[x]=findfa(father[x]);//��*�ݹ�*�ķ�������·������ı��
	return father[x];//��������(�����)
}
int Merge(int a,int b)//�ϲ��ڵ�a,b���ڼ���
{
	int p=findfa(a),q=findfa(b);
	if(p==q)
		return 0;
	if(p>q)//ͳһ��ֵΪС��
		father[p]=q;
	else
		father[q]=p;
	return 1;
}
int kruskal(int n,int m)//�ڵ���n,����m
{
	int ans=0;
	for(int i=0;i<m;i++)//ÿ��ȡ����С��
	{
		if(Merge(e[i].u,e[i].v))//�жϲ���ͬһ����
		{//��ͬһ���ϻ��γɻ�·
			ans+=e[i].w;
			n--;
			if(n==1)//��ȡ��n-1����
				return ans;
		}
	}
	return 0;//m���߱�����,Ҳ����ʹ���нڵ���������,����ͼ����ͨ
}
int main()
{
	int n,m;//�ڵ���n,����m
	while(cin>>n>>m){
		init(n);
		for(int i=0;i<m;i++)
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		sort(e,e+m,cmp);
		int ans=kruskal(n,m);
		if(ans)
			cout<<ans<<endl;
		else
			cout<<"orz"<<endl;
	}
	return 0;
}
