#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
struct edge
{
	int v,nex;
	edge(int v=0,int n=-1):
		v(v),nex(n){}
} e[maxn*maxn];
int cnt=0,head[maxn];
inline void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
int label[maxn],id[maxn],order[maxn];//id[i]表示节点i在序列中的编号
bool vis[maxn];//order[i]为完美消除序列第i个节点,label[x]表示x点与多少个已标号节点相邻
vector<int> vec[maxn];//vec[x]存储*与x个已标号节点相邻*的节点
void mcs(int n)//节点数量
{//复杂度O(n+m)
	memset(vis,0,sizeof(vis));
	memset(label,0,sizeof(label));
	for(int i=1;i<=n;i++)
		vec[0].push_back(i);
	int maxx=0,now=0;
	for(int i=1;i<=n;i++)
	{//从前往后,每轮必定会找出一个
		bool flag=0;
		while(!flag)
		{
			for(int j=vec[maxx].size()-1;j>=0;j--)
			{//从后往前找
				if(vis[vec[maxx][j]])//该节点已经标记过
					vec[maxx].pop_back();
				else{
					flag=1;//找到个未访问的节点
					now=vec[maxx][j];
					break;
				}
			}
			if(!flag)
				maxx--;
		}
		vis[now]=1;//
		order[n-i+1]=now;
		id[now]=n-i+1;//节点x在序列中的位置
		for(int j=head[now];~j;j=e[j].nex)
		{//遍历与now节点相邻的节点
			int v=e[j].v;
			if(!vis[v])
			{
				label[v]++;//v节点与已标号节点数++
				vec[label[v]].push_back(v);
				maxx=max(maxx,label[v]);//找出最大的那个节点
			}
		}
	}
}
int bucket[maxn];
bool isperfect(int n)
{//复杂度O(n+m)
	mcs(n);//计算消除序列并判断是否为完美消除序列
	memset(vis,0,sizeof(vis));//判断序列中的点v_i是否与其后所有点相接
	for(int i=n;i>0;i--)//序列从后向前
	{
		int tot=0,ret=1;//每轮桶清空
		for(int j=head[order[i]];~j;j=e[j].nex)
			if(id[e[j].v]>i)//排在序列编号x后面与x相邻的点集记为:N(x)
				vis[bucket[++tot]=e[j].v]=1;//将序列中在x后且与x邻接点标记并放入桶中
        for(int j=head[bucket[1]];~j;j=e[j].nex)//不一定保证bucket[1]的id为N(x)中最小的啊...
		{//桶空时bucket[1]=0...
			int v=e[j].v;
			if(v!=bucket[1]&&vis[v])
			{//判断N(x)中排在最前面的点是否与N(x)其他点相邻
				ret++;
			}
		}
		for(int j=1;j<=tot;j++)
			vis[bucket[j]]=0;//防止每次memset超时
		if(tot&&ret!=tot)//不全部邻接
			return 0;
	}
	return 1;
}
int main()
{
	int n,m,u,v;
	while(cin>>n>>m&&n&&m)
	{
		memset(head,-1,sizeof(head));
		memset(order,0,sizeof(order));
		cnt=0;
		for(int i=1;i<=n;i++)
			vec[i].clear();
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		cout<<(isperfect(n)?"Perfect\n\n":"Imperfect\n\n");
	}
	return 0;
}
