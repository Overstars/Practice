#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll n,m,k,a[20][20],ans=0,rec[200];
bool vis[2][maxn];
ll get(ll x,bool flag)
{
	ll ret=0;
	if(!flag)
	{//得到第x行
		for(ll i=1;i<=m;i++)
			if(!vis[1][i])//该列没被取走
				ret+=a[x][i];
	}
	else{//得到第x列
		for(ll i=1;i<=n;i++)
			if(!vis[0][i])//i行没被取走
				ret+=a[i][x];
	}
	return ret;
}
void dfs(int tim,ll tot)
{
	if(tot<rec[tim])
		return;
	rec[tim]=max(rec[tim],tot);
	if(tim==k)
	{
		ans=max(ans,tot);
		return;
	}
	for(ll i=1;i<=n;i++)//枚举行
	{
		if(vis[0][i])
			continue;
		vis[0][i]=1;
		dfs(tim+1,tot+get(i,0));
		vis[0][i]=0;
	}
	for(ll i=1;i<=m;i++)
	{
		if(vis[1][i])
			continue;
		vis[1][i]=1;
		dfs(tim+1,tot+get(i,1));
		vis[1][i]=0;
	}
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			cin>>a[i][j];
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}


