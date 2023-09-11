#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG
ll getans(ll x)
{
	ll ans=0;
	while(x>2)
	{
		ans++;
		ll lim=sqrt(x),rec=0;
		if(lim*lim==x)
			rec=1;
		else if(x%lim==0)
			rec=2;
		for(int i=1;i<lim;i++)
			if(x%i==0)
				rec+=2;
		x=rec;
	}
	return ans;
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
	cout<<getans(n)<<endl;
	return 0;
}


