#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int fa[maxn<<2];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
		fa[b]=a;
	else
		fa[a]=b;
	return 1;
}
vector<int> G[maxn<<2];
int in[maxn<<2],ans[maxn<<2],cnt[maxn<<2];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,k,u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		G[u+1].push_back(v+1);
		G[v+1].push_back(u+1);
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>in[i];
		in[i]++;
		cnt[in[i]]++;
	}
	int now=n-k;//k个点被破坏,重新修建
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==0)
		{
			for(auto &v:G[i])
				if(cnt[v]==0&&Merge(i,v))
					now--;
		}
	}
	ans[k+1]=now;
	for(int i=k;i>=1;i--)
	{
		cnt[in[i]]--;
		if(cnt[in[i]]==0)
		{
			now++;//修复该点
			for(auto &v:G[in[i]])
				if(cnt[v]==0&&Merge(in[i],v))
					now--;
		}
		ans[i]=now;
	}
	for(int i=1;i<=k+1;i++)
		cout<<ans[i]<<endl;
	return 0;
}


