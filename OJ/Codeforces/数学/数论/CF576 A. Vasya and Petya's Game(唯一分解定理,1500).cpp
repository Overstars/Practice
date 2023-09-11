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
const int MAXN=2010;
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
	getlist();
	ll n;
	cin>>n;
	vector<ll>ans;
	for(int i=1;prime[i]<=n;i++)
	{
//		ans.push_back(prime[i]);
		ll now=prime[i];
		while(now<=n)
		{
			ans.push_back(now);
			now*=prime[i];
		}
	}
//	sort(ans.begin(),ans.end());
//	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	cout<<ans.size()<<endl;
	for(auto &i:ans)
		cout<<i<<' ';
	return 0;
}
/*
 *给出一个范围在[1,n]的未知数字
 *你要提出最少的y,提问者回答x是否为y的整数倍
 *只需询问素数与素数的幂
 *因为唯一分解定理,其他的数会在上面的询问中筛选出来
 */


