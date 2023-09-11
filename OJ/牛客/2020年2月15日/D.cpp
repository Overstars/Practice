#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5,inf=0x3f3f3f3f;
const ll mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn],b[maxn],siz[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		siz[i]=upper_bound(a+1,a+n+1,b[i])-(a+1);
		if(siz[i]>n)//小于b[i]的个数
			siz[i]=0;
//		printf("siz[%d]=%d\n",i,siz[i]);
	}
	sort(siz+1,siz+n+1);
	ll ans=siz[1];
	for(int i=2;i<=n;i++)
	{
		ll now=siz[i]-i+1;
		if(now<=0)
		{
			ans=0;
			break;
		}
		ans=(ans*now)%mod;
	}
	cout<<ans<<endl;
	return 0;
}


