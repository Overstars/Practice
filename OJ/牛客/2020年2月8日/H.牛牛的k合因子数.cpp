#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
const int MAXN=100010;
int prime[MAXN+1],psize;//psize是素数的个数,prime[i]存着第i个素数
bool isprime[MAXN+1];
void getlist(void)
{
	memset(isprime,1,sizeof(isprime));
	psize=0;
	isprime[1]=false;
	for(int i=2;i<=MAXN;i++)
	{
		if(isprime[i])
			prime[++psize]=i;
		for(int j=1;j<=psize&&i*prime[j]<=MAXN;j++)
		{
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
		}
	}
}
ll rec[maxn],ans[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,m,x;
	cin>>n>>m;
	getlist();
	for(ll i=2;i<=n;i++)
	{
		if(isprime[i])//i不为质数
			continue;
		for(ll j=i;j<=n;j+=i)//枚举合数的倍数
		{
			rec[j]++;//因子j
//			printf("rec[%lld]=%lld\n",j,rec[j]);
		}
	}
//	puts("end");
//	for(int i=2;i<=n;i++)
//		printf("rec[%d]=%lld\n",i,rec[i]);
	for(int i=2;i<=n;i++)
		ans[rec[i]]++;
	while(m--)
	{
		cin>>x;
		cout<<ans[x]<<endl;
	}
	return 0;
}


