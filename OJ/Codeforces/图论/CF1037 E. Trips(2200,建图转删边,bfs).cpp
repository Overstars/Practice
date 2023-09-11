//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int ans[maxn],deg[maxn];
struct node
{
	int x,dd;
	bool operator <(const node &b)const
	{//度数最小的在前
		return dd>b.dd;
	}
};
bool del[maxn],vis[maxn];
vector<pii>G[maxn];
signed main(signed argc, char const *argv[])
{
//	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,k,u,v;
	cin>>n>>m>>k;
	vector<pii>E;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(pii(v,i));
		G[v].push_back(pii(u,i));
		E.push_back(pii(u,v));
		deg[u]++,deg[v]++;
	}
	priority_queue<node>QAQ;
	for(int i=1;i<=n;i++)
		QAQ.push({i,deg[i]});
	int now=n;
	while(!QAQ.empty())
	{
		int x=QAQ.top().x;
		if(del[x])
		{
			QAQ.pop();
			continue;
		}
		if(deg[x]>=k)
			break;
		QAQ.pop();
//		printf("deg[%d]=%d\n",x,deg[x]);
		del[x]=1;//删除
		now--;
		for(pii &e:G[x])//
			if(!del[e.ff])
			{
				deg[e.ff]--;
				QAQ.push({e.ff,deg[e.ff]});
			}
		deg[x]=0;
	}
	ans[m]=now;
	for(int i=m-1;i>0;i--)
	{
		if(QAQ.empty())
			break;
		int a=E[i].ff,b=E[i].ss;
		if(del[a]||del[b])
		{
			ans[i]=now;
			continue;
		}
		vis[i+1]=1;
		deg[a]--;
		deg[b]--;
		QAQ.push({a,deg[a]});
		QAQ.push({b,deg[b]});
		while(!QAQ.empty())
		{
			int x=QAQ.top().x;
			if(del[x])
			{
				QAQ.pop();
				continue;
			}
			if(deg[x]>=k)
			{
//				printf("%d greater than %d\n",x,k);
				break;
			}
			QAQ.pop();
//			printf("deg[%d]=%d,has been deleted in %d.\n",x,deg[x],m-i);
			del[x]=1;//删除
			now--;
			for(pii &e:G[x])//
				if(!vis[e.ss]&&!del[e.ff])
				{
					deg[e.ff]--;
					QAQ.push({e.ff,deg[e.ff]});
				}
			deg[x]=0;
		}
//		for(int j=1;j<=n;j++)
//			printf("deg[%d]=%d\n",j,deg[j]);
		ans[i]=now;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}
/*
 *加边转删边会比较好做
 *将图上保留有效点及其间的边
 *统计这个新图的度数
 *删边,两点度数减一,若小于k,通过队列更新新图及度数
 *问题是怎么确定最初的新图
 *将所有点扔到队列里,不断删除度数小于k的点
*/

