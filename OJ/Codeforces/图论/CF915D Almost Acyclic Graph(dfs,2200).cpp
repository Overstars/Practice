//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=505,inf=0x3f3f3f3f,mod=1000000007;
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
struct edge
{
	int u,v;
} E[maxn*200];
vector<pii>G[maxn];
int deg[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v;
	read(n,m);
//	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		read(u,v);
//		cin>>u>>v;
		G[u].push_back(pii(v,i));
		E[i]={u,v};
		deg[v]++;
	}
	int ok=0;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==0)
			continue;
		int cnt=0;
		vector<int> del(n+1,0);
		del[i]++;
		queue<int>QAQ;
		for(int j=1;j<=n;j++)
			if(deg[j]-del[j]==0)
				QAQ.push(j);
		while(!QAQ.empty())
		{
			int x=QAQ.front();
//			printf("now=%d\n",x);
			cnt++;
			QAQ.pop();
			for(pii &e:G[x])
			{
//				if(e.ss==i)
//					continue;
				del[e.ff]++;
				if(deg[e.ff]-del[e.ff]==0)
					QAQ.push(e.ff);
			}
		}
		if(cnt==n)
		{
			ok=1;
			break;
		}
	}
	printf("%s\n",(ok?"YES":"NO"));
//	cout<<(ok?"YES":"NO")<<endl;
	return 0;
}
/*
 *有向图,无自环,无重边
 *删一条边,能否成为无环图
*/

