#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
bool grid[maxn][maxn];
int n,m,ans,f[maxn][maxn];//f为(i,j)节点向上最大可延伸距离
struct node
{
	int width,height;//宽度,高度
	node(int w=0,int h=0):
		width(w),height(h){}
};
void solve(int x)//第x行以上
{
	stack<node>QAQ;
	node now;
	now.height=f[x][1],now.width=1;
	QAQ.push(now);//第一列入栈
	int suml=0;
	for(int i=2;i<=m;i++)//枚举每一列
	{
		suml=0;
		while(!QAQ.empty()&&f[x][i]<=QAQ.top().height)
		{
			now=QAQ.top();
			QAQ.pop();
			suml+=now.width;
			ans=max(ans,suml*now.height);
		}
		QAQ.push(node(suml+1,f[x][i]));//该矩形为前几个矩形宽度连起来+1
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
	cin>>n>>m;//n行m列
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
	for(int i=1;i<=n;i++)//对第i行及以上部分从左向右进行一次单调栈
		solve(i);
	cout<<ans*3<<endl;
	return 0;
}
