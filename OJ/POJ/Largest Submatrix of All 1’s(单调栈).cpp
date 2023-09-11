//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int maxn=2005;
int f[maxn][maxn];
bool g[maxn][maxn];
int ans=0,n,m;
struct node
{
	int w,h;
	node(int w=0,int h=0):
		w(w),h(h){}
};
void ac(int x)
{
	stack<node> QAQ;
	node now;
	now.w=1,now.h=f[x][1];
	QAQ.push(now);
	for(int i=2;i<=n;i++)
	{
		int suml=0;
		while(!QAQ.empty()&&QAQ.top().h>f[x][i])
		{
			now=QAQ.top();
			QAQ.pop();
			suml+=now.w;
			ans=max(ans,suml*now.h);
		}
		QAQ.push(node(suml+1,f[x][i]));
	}
	int suml=0;
	while(!QAQ.empty())
	{
		now=QAQ.top();
		QAQ.pop();
		suml+=now.w;
		ans=max(ans,suml*now.h);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(scanf("%d%d",&m,&n)==2)
	{
		ans=0;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				int tem;
				scanf("%d",&tem);
				if(tem)
				{
					g[i][j]=1;
					f[i][j]=f[i-1][j]+1;//存储向上可达高度
				}
				else{
					g[i][j]=0;
					f[i][j]=0;
				}
			}
		for(int i=1;i<=m;i++)
			ac(i);
		printf("%d\n",ans);
	}
	return 0;
}
