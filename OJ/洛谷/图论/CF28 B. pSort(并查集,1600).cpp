//#pragma comment(linker, "/STACK:102400000,102400000")
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
int fa[maxn];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
set<int> st[105];
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	fa[b]=a;
	st[a].insert(st[b].begin(),st[b].end());
	return 1;
}
int a[maxn],d[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	bool ok=1;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],st[i].insert(i),fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		if(i-d[i]>=1)
			Merge(i-d[i],i);
		if(i+d[i]<=n)
			Merge(i+d[i],i);
	}
	for(int i=1;i<=n;i++)
		if(st[findfa(i)].count(a[i])==0)
			ok=0;
	cout<<(ok?"YES":"NO")<<endl;
	return 0;
}


