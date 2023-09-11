#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
//struct node
//{
//	ll x,y;
//	node(ll x=0,ll y=0):
//		x(x),y(y){}
//};
//node a[maxn];
ll val(ll x,ll y)
{
	return y*(y-x)*(y-x);
}
ll a[maxn];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,mid=0;
	ll ans=0,rec=LLONG_MAX,x,y;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
//		cin>>a[i].x>>a[i].y;
		a[i]=val(x,y);
//		if(now<rec)
//		{
//			rec=now;
//			mid=i;
//		}
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		ans+=a[i]-a[i-1];
	}
	cout<<ans<<endl;
	return 0;
}


