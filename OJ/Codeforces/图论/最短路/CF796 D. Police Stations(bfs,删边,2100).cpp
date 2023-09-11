//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=3e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
bool vis[maxn];
int p[maxn];
vector<pii>G[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,d,u,v;
	cin>>n>>k>>d;
	queue<int>q;
	for(int i=1;i<=k;i++)
	{
		cin>>u;
		p[u]=i;
		q.push(u);
	}
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(pii(v,i));
		G[v].push_back(pii(u,i));
	}
	vector<int>rec;
	while(!q.empty())
	{
		int x=q.front();
//		printf("x=%d,c=%d\n",x,p[x]);
		q.pop();
		for(auto &e:G[x])
		{
			if(p[e.ff]==0)
			{
				p[e.ff]=p[x];
				q.push(e.ff);
			}
			else if(p[e.ff]!=p[x])
				rec.push_back(e.ss);
		}
	}
	sort(rec.begin(),rec.end());
	rec.erase(unique(rec.begin(),rec.end()),rec.end());
	cout<<rec.size()<<endl;
	for(auto &x:rec)
		cout<<x<<' ';
	return 0;
}
/*
 *可以发现最多删掉k-1条边
 *应该是以警察局为源点,进行bfs染色
 *将指向已经染色的点的边记录
 *思路很快就出了,码完半个小时,出了点沙雕bug
*/

