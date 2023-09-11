//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
struct edge{
	int v,w;
	edge(int _v=0,int _c=0):v(_v),w(_c){}
	bool operator <(const edge &r)const{
		return w>r.w;//重载运算符<
	}
};
vector<edge>G[maxn];
ll dist[maxn],ans=-inf,pos=0;
vector<pii>rec;
bool spfa(int n,int st)
{
	vector<bool>vis(n+2,false);
	vector<int>cnt(n+2,0);
	queue<int>QAQ;
	for(int i=1;i<=n;i++)
		dist[i]=INF;
	QAQ.push(st);
	cnt[st]++;
	dist[st]=0;
	while(!QAQ.empty())
	{
		int u=QAQ.front();
		QAQ.pop();
		vis[u]=0;//出队
		for(auto &e:G[u])
		{
			if(dist[e.v]>dist[u]+e.w)
			{//最短路,因为要求最大值
				dist[e.v]=dist[u]+e.w;
				if(!vis[e.v])
				{
					if(++cnt[e.v]>n+1)
						return true;
					vis[e.v]=1;
					QAQ.push(e.v);
				}
			}
		}
	}
	for(pii &i:rec)//没有羡慕,无解
		if(dist[i.ff]==dist[i.ss])
			return true;
	for(int i=1;i<=n;i++)
		if(dist[i]>ans)
		{
			ans=dist[i];
			pos=st;
		}
	return false;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v,w;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		if(w==1)//u羡慕v,x_v=x_u+1
		{
			G[u].push_back(edge(v,1));
			G[v].push_back(edge(u,-1));
		}
		else{//不知道谁羡慕谁
			G[u].push_back(edge(v,1));
			G[v].push_back(edge(u,1));
			rec.push_back(pii(u,v));
		}
	}
	for(int i=1;i<=n;i++)
		if(spfa(n,i))
			return cout<<"NO"<<endl,0;
	spfa(n,pos);
	cout<<"YES"<<endl;
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		cout<<dist[i]<<' ';
	return 0;
}
/*
 * 2021-05-08-23.41.23
 * 社会不公值=最大-最小
 * 第一个aj -ai <= 1,ai - aj <= -1
 * ai-aj <= 1 ,aj - ai <= 1
 * 以每个点为起点都跑一次
*/

