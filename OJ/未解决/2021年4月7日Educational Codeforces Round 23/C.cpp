//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
int sum(int x)
{
	int ret=0;
	while(x)
	{
		ret+=x%10;
		x/=10;
	}
	return ret;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,s;
	cin>>n>>s;
	int l=1,r=n,ans=n+1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
//		printf("%lld - %lld = %lld\n",mid,sum(mid),mid-sum(mid));
		if(mid-sum(mid)>=s)
		{
			r=mid-1;
			ans=min(ans,mid);
		}
		else
			l=mid+1;
	}
	cout<<n-ans+1<<endl;
//	for(int i=1;i<=1000;i++)
//		printf("%d - %d = %d\n",i,sum(i),i-sum(i));
	return 0;
}
/*
 *2021-04-07-16.32.47
 *n-sum(n)>=s,则符合
*/

