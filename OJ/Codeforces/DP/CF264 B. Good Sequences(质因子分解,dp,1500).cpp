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
const int MAXN=100010;
int phi[MAXN+1],prime[MAXN+1],psize;//psize是素数的个数,prime[i]存着第i个素数
bool isprime[MAXN+1];
void getlist(void)
{
	memset(isprime,1,sizeof(isprime));
	psize=0;
	isprime[1]=false;
	phi[1]=1;
	for(int i=2;i<=MAXN;i++)
	{
		if(isprime[i])
			prime[++psize]=i,phi[i]=i-1;
		for(int j=1;j<=psize&&i*prime[j]<=MAXN;j++)
		{
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
ll a[maxn],dp[maxn];
signed main(signed argc, char const *argv[])
{
//	getlist();
//	for(int i=1;prime[i]<1e5;i++)
//		printf("p[%d]=%d\n",i,prime[i]);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==1)
		return cout<<1<<endl,0;
	for(int i=1;i<=n;i++)
	{
		vector<int>fac;
		ll now=a[i],maxf=0;
		for(int j=2;j*j<=now;j++)
		{
			if(now%j)
				continue;
			fac.push_back(j);
			while(now%j==0)
				now/=j;
		}
		if(now>1)
			fac.push_back(now);
		for(int &f:fac)
			maxf=max(maxf,dp[f]);
		for(int &f:fac)
			dp[f]=maxf+1;
	}
	cout<<*max_element(dp,dp+maxn)<<endl;
	return 0;
}


