#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll POW(ll a,ll b,ll p)
{
	ll ans = 1;
	while(b){
		if(b&1)
			ans = (ans%p*a%p) % p;
		a = (a%p*a%p) % p;
		b >>= 1;
	}
	return ans%p;
}
ll C(ll n,ll m,ll p)
{
	if(m > n)return 0;
	if(m == n)return 1;
	if(m > n - m)m = n - m;
	ll a = 1, b = 1 ;
	for(ll i = 0 ; i < m ; i++){
		a = a * (n - i) % p;
		b = b * (i + 1) % p;
	}
	return a * POW(b,p-2,p) % p;
}
ll lucas(ll n,ll m,ll p=mod){//C(n,m)%p
	if(m == 0)
		return 1;
	return C(n%p,m%p,p)*lucas(n/p,m/p,p)%p;
}
int fa[15],siz[15];
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
		fa[b]=a,siz[a]+=siz[b];
	else
		fa[a]=b,siz[b]+=siz[a];
	return 1;
}
bool vis[maxn];
ll a[13],r[4],m,ans=0;
vector<ll>vec;//各集合大小
void dfs(int col,int vis)//col=1,2,3
{
	if(col==4)
	{
		ans++;
		return;
	}
	for(int i=0;i<=(1ll<<(int)vec.size())-1;i++)
	{
		ll now=0,num=__builtin_popcount(i);//此时集合的大小
		if(vis&i)
			continue;
		for(int tmp=1,cc=0;tmp<=i;tmp<<=1,cc++)
		{
			if(i&tmp)
				now+=vec[cc];
		}
		if(now==a[col])
		{
			dfs(col+1,vis|i);
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	for(int i=1;i<=12;i++)
		fa[i]=i,siz[i]=1;
	for(int i=1;i<=4;i++)
		cin>>a[i];
	cin>>m;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		Merge(x,y);
	}
	for(int i=1;i<=12;i++)
	{
		int now=findfa(i);
		if(vis[now])
			continue;
		vis[now]=1;
		vec.push_back(siz[now]);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}


