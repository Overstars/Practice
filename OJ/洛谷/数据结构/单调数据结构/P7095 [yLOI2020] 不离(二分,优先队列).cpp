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
struct node
{
	int a,b,c,d;
	node(){}
	node(int a,int b,int c,int d):
		a(a),b(b),c(c),d(d){}
	bool operator <(const node &y)const
	{
		return b>y.b;
	}
} R[maxn];
int n;
bool check(ll x)
{
	for(int i=1;i<=n;i++)
	{
		if(x<R[i].a)
			return 0;
		x+=R[i].c;
	}
	return 1;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,a,b,c,d;
	cin>>t;
//	while(t--)
	{
		cin>>n;
		if(n==0)
			return cout<<"0 0"<<endl,0;
		for(int i=1;i<=n;i++)
		{
			cin>>a>>b>>c>>d;
			R[i]=node(a,b,c,d);
		}
		sort(R+1,R+n+1,[](const node &x,const node &y){
				return x.a<y.a;
			});
		ll ans1=INF,ans2=INF,l=0,r=inf;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(check(mid))
			{
				ans1=min(ans1,mid);
				r=mid-1;
			}
			else
				l=mid+1;
		}//ans1即为答案力量值
		l=0,r=inf;
		while(l<=r)
		{
			ll mid=(l+r)>>1,cnt=0,pos=1;
			ll ca=ans1,cb=mid;
			priority_queue<node>q;
			bool ok=0;
			while(1)
			{
				while(pos<=n&&R[pos].a<=ca)
					q.push(R[pos++]);
				if(q.empty()||cb<q.top().b)//不能再取了
					break;
				while(!q.empty()&&cb>=q.top().b)
				{
					node now=q.top();
					q.pop();
					cnt++;
					ca+=now.c;
					cb+=now.d;
				}
				if(cnt==n)
				{
					ok=1;
					break;
				}
			}
			if(ok)
			{
				ans2=min(ans2,mid);
				r=mid-1;
			}
			else
				l=mid+1;
		}
		cout<<ans1<<' '<<ans2<<endl;
	}
	return 0;
}
/*
 *很明显力量值要优先确定且不会改变
 *单独考虑力量值二分确定即可,似乎也可以贪出来
 *之后考虑在该力量值不变情况下确定精神值
*/

