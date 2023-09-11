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
	ll n;
	cin>>n;
	vector<ll> rec;
	for(ll i=1;i*i<=n;i++)//枚举约数
	{
		if(n%i)
			continue;
		ll x=n/i;//x项,首项为1,公差为i
		rec.push_back(x+(x*(x-1)/2*i));
		if(i*i==n)
			break;
		rec.push_back(i+(i*(i-1)/2*x));//另一个约数
	}
	sort(rec.begin(),rec.end());
	rec.erase(unique(rec.begin(),rec.end()),rec.end());
	for(ll i=0;i<rec.size();i++)
		cout<<rec[i]<<' ';
	return 0;
}


