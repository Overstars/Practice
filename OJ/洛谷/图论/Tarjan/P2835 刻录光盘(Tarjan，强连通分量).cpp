#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=205;
vector<int> G[maxn];
int tot=0,Index=0,cnt=0;
int dfn[maxn],low[maxn],belong[maxn],stk[maxn];
bool vis[maxn];
void tarjan(int x)
{
	dfn[x]=low[x]=++tot;
	stk[++Index]=x;
	vis[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		if(!dfn[G[x][i]])
		{
			tarjan(G[x][i]);
			low[x]=min(low[x],low[G[x][i]]);
		}
		else if(vis[G[x][i]])
			low[x]=min(low[x],dfn[G[x][i]]);
	}
	if(dfn[x]==low[x])
	{
		cnt++;//��ǿ��ͨ����
		do{
			vis[stk[Index]]=0;
			belong[stk[Index]]=cnt;
			Index--;
		}while(stk[Index+1]!=x);
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int v;
		while(cin>>v&&v)
		{
			if(v!=i)
				G[i].push_back(v);//i�ſ��԰����ϸ�v
		}
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	int have[maxn]={0};//ͳ�ƾ�����ȵ�ǿ��ͨ����
	memset(have,0,sizeof(have));
	for(int i=1;i<=n;i++)
		for(int j=0;j<G[i].size();j++)
			if(belong[i]!=belong[G[i][j]])
				have[belong[G[i][j]]]++;
	int ans=0;
	for(int i=1;i<=cnt;i++)
		if(!have[i])//û����ȵ�ǿ��ͨ������
			ans++;
//	if(!ans)
//		ans=1;
	cout<<ans<<endl;
	return 0;
}
