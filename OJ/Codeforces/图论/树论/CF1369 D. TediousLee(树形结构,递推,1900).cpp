//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
ll dp0[maxn]={0,1,1},dp1[maxn]={0,0,1,3,5},dp3[maxn]={0,0,0},rec[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	for(ll i=3;i<maxn;i++)
	{
		dp1[i]=dp0[i-1]%mod;
		dp0[i]=(dp0[i-1]%mod+2*dp0[i-2]%mod)%mod;
		dp3[i]=dp1[i-1]%mod;//新增的3儿子节点数量
		rec[i]=(rec[i-3]+dp3[i])%mod;
//		printf("%lld:%lld,%lld,%lld\n",i,dp0[i],dp1[i],dp3[i]);
	}
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll ans;
//		if(n>=3)
//			ans=(dp3[n]+dp3[n-2])%mod*4%mod;
//		else
//			ans=
		cout<<rec[n]*4%mod<<endl;
	}
	return 0;
}
/*
	求claw数量
	可以很容易发现儿子数目0与1的节点数量递推关系...
	但是claw和他们的关系不好确定...
	claw必定有一个尾巴,这个尾巴会在下一层形成一个新的claw
	claw翅膀会在两层后形成新的claw
	贪心,新的一层必须取,然后每隔三层取一层
	用时一小时...
*/

