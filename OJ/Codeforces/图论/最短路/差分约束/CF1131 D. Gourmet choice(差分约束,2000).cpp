//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=2005,inf=0x3f3f3f3f,mod=1000000007;
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
ll dist[maxn],cnt[maxn];
bool spfa(int n)
{
	vector<bool>vis(n+2,false);
	queue<int>QAQ;
	int st=n+1;//超级源点
	for(int i=1;i<=n;i++)
		G[st].push_back(edge(i,0));
	QAQ.push(st);
	cnt[st]++;
	dist[st]=1;
	while(!QAQ.empty())
	{
		int u=QAQ.front();
		QAQ.pop();
		vis[u]=0;//出队
		for(auto &e:G[u])
		{
			if(dist[e.v]<dist[u]+e.w)
			{//最长路,因为要求最小值
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
	return false;
}
char s[maxn][maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m;
    cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i]+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='<')//i<j -> i<=j-1 -> i-j<=-1
				G[i].push_back(edge(n+j,1));//j-i>=1
			else if(s[i][j]=='>')//i>j -> i-1>=j -> j-i<=-1
				G[n+j].push_back(edge(i,1));//i-j>=1
			else{
				G[i].push_back(edge(n+j,0));
				G[n+j].push_back(edge(i,0));
			}
		}
	if(spfa(n+m))
		return cout<<"No"<<endl,0;
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++)
		cout<<dist[i]<<' ';
	cout<<endl;
	for(int i=n+1;i<=n+m;i++)
		cout<<dist[i]<<' ';
	cout<<endl;
	return 0;
}
/*
 * 2021-05-08-17.32.36
 * 使a,b中最大元素最小
*/

