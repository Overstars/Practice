//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//const ll INF=0x3f3f3f3f3f3f3f3f;
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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n;
	const ll INF=1e15+5;
	ll ans=INF,cnt=0;
	cin>>n;
	vector<ll>a;
	for(ll i=1,tmp;i<=n;i++)
	{
		cin>>tmp;
		if(tmp)//排除掉0
			a.push_back(tmp);
	}
	n=a.size();
	if(n>=64*2+1)//鸽巢原理,不为全0的达到64*2+1
		return cout<<3<<endl,0;
	vector<vector<ll>>dis(n,vector<ll>(n,INF)),mp(n,vector<ll>(n,INF));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if((a[i]&a[j])&&i!=j)
				mp[i][j]=dis[i][j]=1;
			else
				mp[i][j]=dis[i][j]=INF;
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<k;i++)
			for(int j=0;j<i;j++)
				ans=min(ans,dis[i][j]+mp[i][k]+mp[k][j]);
//		cout<<ans<<endl;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	if(ans>=INF)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}


