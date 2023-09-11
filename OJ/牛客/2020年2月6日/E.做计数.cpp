#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG//<<setiosflags(ios::fixed)<<setprecision(9)
bool jud(ll x,ll y)
{
	if(x<y)
		swap(x,y);
	for(ll j=2;j*j<=y;j++)
	{
		while(y%(j*j)==0)
			y/=j*j;
	}
	for(ll i=2;i*i<=x;i++)
		while(x%(i*i)==0)
			x/=i*i;
	return x==y;
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
	ll n;
//	cin>>n;
	for(n=1;n<=100;n++)
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
	//		ans[i]=ans[i-1];
			for(int j=i;j*i<=n;j++)
			{
				if(jud(j,i))
				{
					if(i==j)
						ans++;
					else
						ans+=2;
				}
			}
		}
		cout<<"ans["<<n<<"]="<<ans<<endl;
	}
//	for(int i=1;i<=n;i++)
//		cout<<"ans["<<i<<"]="<<ans[i]<<endl;
	return 0;
}


