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
int pre[maxn][2],ok=0,tar=0,vv[maxn];
bool vis[maxn][2];
list<int>ans;
vector<int>G[maxn];
void dfs(int x,bool sta)
{
	if(vis[x][sta]||ok==2)
		return;
	ans.push_back(x);
	vv[x]=1;
	vis[x][sta]=1;
	for(int &v:G[x])
	{
		if(vv[v]==1)//有返祖边,即有环
			ok=max(ok,1);
		if(vis[v][!sta])//奇偶性不同
			continue;
		if(G[v].size()==0&&!sta&&ok!=2)//奇数,且无出边,之前未输出答案
		{
			ok=2;
			ans.push_back(v);
		}
		dfs(v,!sta);
	}
	if(ok!=2)
		ans.pop_back();
	vv[x]=2;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,s;
	cin>>n>>m;
	for(int i=1,c,v;i<=n;i++)
	{
		cin>>c;
		for(int j=1;j<=c;j++)
		{
			cin>>v;
			G[i].push_back(v);
		}
	}
	cin>>s;
	dfs(s,0);
	if(ok==2)
	{
		cout<<"Win"<<endl;
		for(int &i:ans)
			cout<<i<<' ';
	}
	else if(ok==1)
		cout<<"Draw"<<endl;
	else if(ok==0)
		cout<<"Lose"<<endl;
	return 0;
}
/*
 *很明显假如从s有一条到叶子距离为奇数的路径,则WIN
 *假如从s可达一个环,至少平局
 *否则就是lose
 *s->环->叶子,走多少遍环也要考虑进去
 */

