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
vector<int>G[maxn];
bool vis[maxn];
int dfs(int x)
{
	if(vis[x])
		return 0;
	int ret=G[x].size();
	vis[x]=1;
	for(auto &v:G[x])
		ret+=dfs(v);
	return ret;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int c1=0,c2=0,c3=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			int num=dfs(i)/2;//边的数目
//			cerr<<"num = "<<num<<endl;
			if(num<=1)
				c1++;
			else if(num%2==0)
				c2++;
			else
				c3++;
		}
	}
	bool ok=0;
	if(c1%2==0)//偶数则先手败
		ok=0;
	if(c1%2==0&&c3%2==1)
		ok=1;
	if(c1%2==1&&c2%2==1)
		ok=1;
	cout<<(ok?"Alice":"Bob")<<endl;
	return 0;
}
/*
 * 2021-07-26-15.22.29
 * C:\Users\dell\Desktop\C++\OJ\牛客\2021牛客暑期多校训练营\4-F.cpp
 *
*/

