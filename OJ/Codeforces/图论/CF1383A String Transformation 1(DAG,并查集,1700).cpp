//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
char a[maxn],b[maxn];
set<int>st[30];
int ans=0;
bool vis[30]={0},tar[30],ok,pre;//目标字母已经转化过
void dfs(int x)
{
	if(vis[x])//已经计算过了
		return;
	vis[x]=1;
	for(auto &v:st[x])
	{
		if(!vis[v])
		{
			ans++;
			dfs(v);
		}
	}
}
int fa[maxn];
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
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n>>a+1>>b+1;
		for(int i=0;i<=27;i++)
			st[i].clear(),vis[i]=tar[i]=0,fa[i]=i;
		ok=1,pre=0,ans=0;;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>b[i])
			{
				ok=0;
				break;
			}
			else if(a[i]<b[i])
				st[a[i]-'a'+1].insert(b[i]-'a'+1);
			if(Merge(a[i]-'a'+1,b[i]-'a'+1))
				ans++;
		}
		if(!ok)
		{
			cout<<-1<<endl;
			continue;
		}
//		for(int i=1;i<=26;i++)
//		{
//			if(!vis[i]&&st[i].size())
//			{
//				vis[i]=1;
//				for(auto &v:st[i])
//				{
//					if(tar[i]&&tar[v])
//						continue;
//					tar[v]=1;
//					if(!vis[v])
//						ans++;
//				}
////				pre=1;
////				dfs(i);
//			}
//		}
		cout<<ans<<endl;
	}
	return 0;
}


