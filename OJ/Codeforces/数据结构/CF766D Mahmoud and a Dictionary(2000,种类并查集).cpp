//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
int fa[maxn<<1],rnk[maxn<<1];
void init(int n)
{
	for(int i=1;i<=2*n;i++)
		fa[i]=i,rnk[i]=1;
}
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
int query(int x,int y)
{//下标x与y是否在同一个集合中
	return findfa(x)==findfa(y);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,q,t;
	string s,a,b;
	vector<string>rec;
	map<string,int>mp;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		mp[s]=i;
//		rec.push_back(s);
	}
	init(n);
	for(int i=1;i<=m;i++)
	{
		cin>>t>>a>>b;
		int x=mp[a],y=mp[b];
		bool ok=1;
		if((query(x,y)&&t==2)||(query(x,n+y)&&t==1))
			ok=0;
		else{
			if(t==1)//标记为相邻
			{
				Merge(x,y);
				Merge(n+x,n+y);
			}
			else{//标记为冲突
				Merge(x,n+y);
				Merge(y,n+x);
		4	}
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
	while(q--)
	{
		cin>>a>>b;
		if(query(mp[a],mp[b]))
			cout<<1<<endl;
		else if(query(mp[a],mp[b]+n))
			cout<<2<<endl;
		else
			cout<<3<<endl;
	}
	return 0;
}


