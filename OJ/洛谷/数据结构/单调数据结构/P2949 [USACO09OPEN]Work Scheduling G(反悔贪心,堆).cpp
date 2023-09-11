//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
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
//int d[maxn],p[maxn];
struct node
{
	int d,p;
	node(){}
	node(int a,int b):
		d(a),p(b){}
	bool operator <(const node &y)const
	{
//		if(d==y.d)
//			return p<y.p;
		return d<y.d;
	}
} a[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,x,y;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].d>>a[i].p;
//		cin>>d[i]>>p[i];//截止时间d与获利p
	}
	sort(a+1,a+n+1);
	priority_queue<ll,vector<ll>,greater<ll>>q;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{//假设每一道工作都做
		if(q.size()<a[i].d)//可以做,直接做
		{
			ans+=a[i].p;
			q.push(a[i].p);
		}
		else if(q.top()<a[i].p)//如果比之前做过的一个更优
		{
				ans+=a[i].p-q.top();
				q.pop();
				q.push(a[i].p);
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *反悔贪心题
*/

