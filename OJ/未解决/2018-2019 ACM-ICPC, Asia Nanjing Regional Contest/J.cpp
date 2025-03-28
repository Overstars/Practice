//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
const int MAXN=1010;
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
int a[maxn];
vector<int>f[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	getlist();
//	cout<<psize<<endl;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	set<int>st;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=psize;j++)
		{
			int g=prime[j];
			if(a[i]%g==0)
			{
				f[g].push_back(i);
				st.insert(g);
				while(a[i]%g==0)
					a[i]/=g;
			}
		}
		if(a[i]>1)
		{
			st.insert(a[i]);
			f[a[i]].push_back(i);
		}
	}
	ll ans=0;
	for(auto &x:st)
	{//质因子
		f[x].push_back(n+1);
		int lim=f[x].size();
//		printf("p = %lld\n",x);
		for(int j=0;j<lim-1;j++)
		{
//			if(j==0)
//			printf("%lld*%lld,%lld-%lld\n",f[x][j],(f[x][j+1]-f[x][j]),f[x][j+1],f[x][j]);
			ans+=(f[x][j])*(f[x][j+1]-f[x][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
10
99 62 10 47 53 9 83 33 15 24

10
6 7 5 5 4 9 9 1 8 12
*/
/*
 * 2021-04-24-14.49.24
*/

