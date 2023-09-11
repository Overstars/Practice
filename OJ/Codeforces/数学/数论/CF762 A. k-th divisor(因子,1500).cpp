#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
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
	ll n,k;
	cin>>n>>k;
	vector<ll>ans;
	for(ll i=1;i*i<=n;i++)
	{
		if(n%i)
			continue;
		ans.push_back(i);
		if(i*i!=n)
			ans.push_back(n/i);
	}
	sort(ans.begin(),ans.end());
//	for(auto &i:ans)
//		cout<<i<<endl;
	if(ans.size()>k-1)
		cout<<ans[k-1]<<endl;
	else
		cout<<-1<<endl;
	return 0;
}


