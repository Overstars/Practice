//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
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
struct node
{
	int l,r,id;
};
int a[maxn];
int query(int l,int r)
{

}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,q,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		l=((l+ans)%n)+1;
		r=((r+ans)%n)+1;
		if(l>r)
			swap(l,r);
		cout<<query(l,1)<<'\n';
	}
	return 0;
}
/*
 *2021-04-02-20.32.48
 *同一种数只能选k个
 *问[l,r]区间内能取走多少个值,强制在线
 *区间数目容易想到前缀和
*/

