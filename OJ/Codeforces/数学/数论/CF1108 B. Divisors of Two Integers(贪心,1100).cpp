#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'|ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,x=1,y=1;
	cin>>n;
	vector<ll>d(n);
	for(int i=0;i<n;i++)
		cin>>d[i];
	sort(d.begin(),d.end());
	for(auto &i:d)
	{
		if(i==__gcd(x,i))
			y*=i/__gcd(y,i);
		else
			x*=i/__gcd(x,i);
	}
	cout<<x<<' '<<y<<endl;
	return 0;
}

