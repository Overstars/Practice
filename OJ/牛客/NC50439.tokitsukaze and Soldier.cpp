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
struct node
{
	ll v,s;
	node(ll v,ll s):
		v(v),s(s){}
};
ll dp[maxn];//dp[i]表示人数为i时最大数
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	vector<node>vec;
	cin>>n;
	for(int i=1,v,s;i<=n;i++)
	{
		cin>>v>>s;
		vec.push_back(node(v,s));
	}
	sort(vec.begin(),vec.end(),*(const node&a,const node &b){
			return a.s>b.s;
		});
	priority_queue<ll,vector<ll>,greater<ll> >p;b
	ll cnt=n,ans=0;
	while(cnt>0)
	{


	}
	cout<<ans<<endl;
	return 0;
}


