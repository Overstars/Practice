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
ll n,m,k,a[20][20],sum[20],ans=0;
bool vis[20];
ll get(ll x)//得到第x列
{
	ll ret=0;
	for(ll i=1;i<=n;i++)
		if(!vis[i])//i行没被取走
			ret+=a[i][x];
	return ret;
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
	for(ll i=1;i<=n;i++)
	{//sum[i]为第i行的和
		for(ll j=1;j<=m;j++)
			sum[i]+=a[i][j];
	}
	for(ll i=0;i<=(1<<n);i++)
	{
		ll cnt=0;//i有多少位为1
		for(int i=1;i<=n;i++)
			vis[i]=0;
		for(ll x=i;x>0;x>>=1)
		{
			if(x&1)
				cnt++;
		}
		if(cnt>k||cnt>n)
			continue;
		ll now=0;
		for(ll j=1;(1<<(j-1))<=i;j++)
		{
			if(i&(1<<(j-1)))
			{
				now+=sum[j];
				vis[j]=1;
			}
		}
		priority_queue<ll,vector<ll>,less<ll> >q;
		for(ll j=1;j<=m;j++)//m列
		{
			q.push(get(j));//第j列
		}
		ll tmp=k-cnt;
		while(tmp--&&!q.empty())
		{
			now+=q.top();
			q.pop();
		}
		ans=max(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}


