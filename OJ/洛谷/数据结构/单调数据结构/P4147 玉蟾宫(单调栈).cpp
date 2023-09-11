#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
bool grid[maxn][maxn];
int n,m,ans,f[maxn][maxn];//fΪ(i,j)�ڵ����������������
struct node
{
	int width,height;//���,�߶�
	node(int w=0,int h=0):
		width(w),height(h){}
};
void solve(int x)//��x������
{
	stack<node>QAQ;
	node now;
	now.height=f[x][1],now.width=1;
	QAQ.push(now);//��һ����ջ
	int suml=0;
	for(int i=2;i<=m;i++)//ö��ÿһ��
	{
		suml=0;
		while(!QAQ.empty()&&f[x][i]<=QAQ.top().height)
		{
			now=QAQ.top();
			QAQ.pop();
			suml+=now.width;
			ans=max(ans,suml*now.height);
		}
		QAQ.push(node(suml+1,f[x][i]));//�þ���Ϊǰ�������ο��������+1
	}
	suml=0;
	while(!QAQ.empty())
	{
		now=QAQ.top();
		QAQ.pop();
		suml+=now.width;
		ans=max(ans,suml*now.height);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char ch;
	cin>>n>>m;//n��m��
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch=='F')
			{
				grid[i][j]=1;
				f[i][j]=f[i-1][j]+1;
			}
		}
	for(int i=1;i<=n;i++)//�Ե�i�м����ϲ��ִ������ҽ���һ�ε���ջ
		solve(i);
	cout<<ans*3<<endl;
	return 0;
}
