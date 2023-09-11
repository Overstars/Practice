#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int sum[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,l,r;
	cin>>n>>m;
	while(m--)
	{
		cin>>l>>r;
		sum[l]++;
		sum[r+1]--;
	}
	vector<int>v;
	for(int i=1,now=0;i<=n;i++)
	{
		now+=sum[i];
		v.push_back(now);
	}
	sort(v.begin(),v.end(),greater<int>());
	ll ans=0;
	for(auto &x:v)
		ans+=(n--)*x;
	cout<<ans<<endl;
	return 0;
}


