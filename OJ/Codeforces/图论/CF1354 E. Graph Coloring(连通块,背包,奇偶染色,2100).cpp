//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=5e3+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
vector<int>G[maxn];
int vis1[maxn],ans2[maxn],ok=1;
pii dfs(int vis[],int x,int s)
{//ff为连通块大小,ss为连通块当前2的数量
	vis[x]=s;
	pii now=pii(1,0);
	if(s==2)
		now.ss++;
	for(int &v:G[x])
	{
		if(vis[v]==vis[x])
			ok=0;
		if(vis[v])
			continue;
		pii c=dfs(vis,v,(s==2)?1:2);
		now.ff+=c.ff;
		now.ss+=c.ss;
	}
	return now;
}
bool dp[maxn][maxn],pre[maxn][maxn];
vector<bool>ans1;
vector<pii>r;
void Find(int x,int siz)
{
	if(x==0)
		return;
	if(pre[x][siz])
	{
		Find(x-1,siz-r[x-1].ss);
		ans1.push_back(1);//从1开始
	}
	else{
		Find(x-1,siz-(r[x-1].ff-r[x-1].ss));
		ans1.push_back(0);//从2开始
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,n1,n2,n3,u,v;
	cin>>n>>m>>n1>>n2>>n3;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<int>rec;
	for(int i=1;i<=n;i++)
		if(!vis1[i])
		{
			rec.push_back(i);
			r.push_back(dfs(vis1,i,1));
		}
	dp[0][0]=1;
	for(int i=1;i<=r.size();i++)
	{
		int v1=r[i-1].ff-r[i-1].ss,v2=r[i-1].ss;
		for(int j=n2;j>=min(v1,v2);j--)
		{
			if(j>=v1&&dp[i-1][j-v1])
			{
				dp[i][j]=1;
				pre[i][j]=0;//由另一种转移过来
			}
			if(j>=v2&&dp[i-1][j-v2])
			{
				dp[i][j]=1;
				pre[i][j]=1;
			}
		}
	}
	if(!ok||!dp[r.size()][n2])
		cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		Find(r.size(),n2);
		for(int i=0;i<ans1.size();i++)
		{
			if(ans1[i])
				dfs(ans2,rec[i],1);
			else
				dfs(ans2,rec[i],2);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(ans2[i]==2)
				cout<<2;
			else if(cnt<n1)
			{
				cnt++;
				cout<<1;
			}
			else
				cout<<3;
	}
	return 0;
}
/*
 *奇环时一定无解
 *对于每个连通块,2的数量固定,可黑白染色求
 *其他点1和3都是任意指定的
 *emm,我咋觉得5e3的背包跑不了...
 *跑起来好像奇偶染色标记答案也挺麻烦的
 */
