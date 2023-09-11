//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
struct edge
{
	int u,v,w;
};
vector<edge>rec;
map<int,int>dp[maxn];//dp[x]表示以x结束,权值为ff的最大长度ss
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
		rec.push_back((edge){u,v,w});
	}
	sort(rec.begin(),rec.end(),[](const edge &a,const edge &b){
			return a.w<b.w;
		});
	int ans=0;//dp[v]=dp[u]+1
	map<int,int>::iterator it,it2;
	auto get = [&it](int x,int k)
	{
		int ret=0;
		it=dp[x].lower_bound(k);
		if(it!=dp[x].begin())
			ret=(--it)->ss;
		return ret;
	};
	for(edge &e:rec)
	{
		u=e.u,v=e.v,w=e.w;
		int now=get(u,w)+1;//以u结尾的最大长度
//		if(now>get(v,w))
		{//要更新答案
			dp[v][w]=max(dp[v][w],now);
			it=dp[v].lower_bound(w);
			int pre=0;
			for(it2=dp[v].begin();it2!=it&&it2!=dp[v].end();)
			{
				pre=max(pre,it2->ss);
				it2=dp[v].erase(it2);
			}
			dp[v][w-1]=pre;
		}
		ans=max(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}
/*
 * 2021-04-26-18.30.56
*/

