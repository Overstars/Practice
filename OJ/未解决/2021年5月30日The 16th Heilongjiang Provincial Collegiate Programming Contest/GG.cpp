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
amespace Tarjan
{
	int bcc,top,tot,n;
	vector<int> mp[MAX];
	vector<PII > bridge;
	int low[MAX],dfn[MAX],belong[MAX],fa[MAX];
	int stk[MAX];
	int cut[MAX],add_block[MAX];
	void dfs(int x,int pre)
	{
		int to,i,tmp,k,son;
		stk[top++]=x;
		low[x]=dfn[x]=++tot;
		fa[x]=pre;
		son=k=0;
		for(auto to:mp[x])
		{
		if(to==pre&&!k)
			{
			k++;
			continue;
			}
		if(!dfn[to])
		{
		son++;
		dfs(to,x);
		low[x]=min(low[x],low[to]);
		if(x!=pre&&low[to]>=dfn[x])
		{
		cut[x]=1;
		add_block[x]++;
		}
		if(low[to]>dfn[x]) bridge.pb(MP(x,to));
		}
		else low[x]=min(low[x],dfn[to]);
		}
		if(x==pre&&son>1)
		{
		cut[x]=1;
		add_block[x]=son-1;
		}
		if(low[x]==dfn[x])
		{
		bcc++;
		do
		{
		tmp=stk[--top];
		belong[tmp]=bcc;
		}while(tmp!=x);
		}
		}
		void work(int _n,vector<int> e[])
		{
		n=_n;
		for(int i=1;i<=n;i++)
		{
		mp[i]=e[i];
		low[i]=dfn[i]=fa[i]=stk[i]=0;
		cut[i]=add_block[i]=0;
		}
		bcc=top=tot=0;
		bridge.clear();
		for(int i=1;i<=n;i++)
		{
		if(!dfn[i]) dfs(i,i);
		}
		}
		void rebuild(vector<int> e[])
		{
		int i,t;
		for(i=1;i<=n;i++) e[i].clear();
		for(i=1;i<=n;i++)
		{
		t=fa[i];
		if(belong[i]!=belong[t])
		{
		e[belong[i]].pb(belong[t]);
		e[belong[t]].pb(belong[i]);
		}
		}
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif

	return 0;
}
/*
 * 2021-05-30-14.49.14
 * C:\Users\dell\Desktop\C++\OJ\未解决\2021年5月30日The 16th Heilongjiang Provincial Collegiate Programming Contest\GG.cpp
 *
*/

