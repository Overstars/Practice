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
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll p,y;
	cin>>p>>y;//去掉[2,y]内所有[2,p]的倍数,(p,y]的素数
	ll ans=-1;
	for(ll i=y;i>p;i--)
	{
		bool flag=1;
		for(ll j=2;j<=p&&j*j<=y&&flag;j++)
		{
			if(i%j==0)
				flag=0;
		}
		if(flag)
		{
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}


