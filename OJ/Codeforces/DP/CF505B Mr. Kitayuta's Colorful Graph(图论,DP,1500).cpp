#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
struct edge
{
	int v,c,nex;
}e[maxn<<1];
int n,m,head[maxn],cnt;
void add(int u,int v,int c)
{
	e[++cnt].v=v;
	e[cnt].c=c;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
bool vis[maxn][maxn];//以j颜色访问i节点
int dp[maxn][maxn][maxn];
void dfs(int x,string s,int col)//下来时的颜色
{
	vis[x][col]=1;
	for(int i=head[x];~i;i=e[i].nex)
	{
		int v=e[i].v,c=e[i].c;
		if(vis[v][c])
			continue;
//		for(int j=0;j<s.length();j++)
//			cout<<(char)(s[j]+'0')<<' ';
//		cout<<endl;
		if(col==c)
		{
			for(int j=0;j<s.length();j++)
				dp[(int)s[j]][v][col]=1;
			dp[x][v][col]=1;
			dfs(v,s+(char)x,col);
		}
		else
		{
			string tem;
			tem+=(char)x;
			dp[x][v][c]=1;
			dfs(v,tem,c);
		}
	}
//	vis[x][col]=0;
}
int main()
{
	memset(head,-1,sizeof(head));
	int u,v,c,q;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>c;
		add(u,v,c);
		add(v,u,c);
	}
	string str;
	cin>>q;
//	for(int i=1;i<=6;i++)
//		for(int j=1;j<=6;j++)
//			for(int k=1;k<=6;k++)
//				printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][j][k]);
	//dp[i][j][k]节点i和j之间被k颜色的边连着
	while(q--)
	{
		cin>>u>>v;
		memset(vis,0,sizeof(vis));
		dfs(u,str,0);
		int ans=0;
		for(int i=1;i<=m;i++)
			ans+=max(dp[u][v][i],dp[v][u][i]);
		cout<<ans<<endl;
	}
	return 0;
}
