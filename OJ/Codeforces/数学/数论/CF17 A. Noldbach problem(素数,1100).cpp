#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG
const int MAXN=10001;
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
int cnt[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	getlist();
//	for(int i=1;i<=psize;i++)
//		printf("pri[%d]=%d\n",i,prime[i]);
	for(int i=3,tot=1;i<=1000;i++)
	{
		if(isprime[i])
		{
			tot++;
			for(int j=2;j<tot;j++)
			{
				if(i==prime[j-1]+prime[j-2]+1)
				{
					cnt[i]++;
					break;
				}
			}
		}
		cnt[i]+=cnt[i-1];
//		printf("c[%d]=%d\n",i,cnt[i]);
	}
	int n,k;
	cin>>n>>k;
	if(cnt[n]>=k)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}


