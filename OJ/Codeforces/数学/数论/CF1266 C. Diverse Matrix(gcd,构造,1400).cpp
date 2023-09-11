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
const int MAXN=300010;
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
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
//	getlist();
	vector<ll>p,np;
	int r,c;
	cin>>r>>c;
	for(ll i=1;i<=max(r,c);i++)
		p.push_back(i+1);
	if(r==c&&r==1)
		cout<<"0\n";
	else if(r>=c)
	{
		for(ll i=2;i<=r+1;i++)
		{
			printf("%lld ",i);
			for(ll j=r+2;j<=r+c;j++)
				printf("%lld ",j*i);
			printf("\n");
		}
	}
	else{
		for(ll i=0;i<c;i++)//c更大
			printf("%lld ",p[i]);
		printf("\n");
		for(ll i=c+1;i<r+c;i++)
		{
			for(ll j=0;j<c;j++)//r比c小
			{
				printf("%lld ",i*p[j]);
			}
			printf("\n");
		}
	}
	return 0;
}


