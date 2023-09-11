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
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll t,p;
	cin>>t;
	while(t--)
	{
		cin>>p;
		ll ans=1;
		for(ll i=2;i*i<=p;i++)
		{
			ll cnt=0;
			while(p%i==0)
			{
				cnt++;
				p/=i;
			}
			ll l=1,r=cnt*i,now=cnt*i;
			while(l<=r)
			{//mid为区间端点,tot为因子数量
				ll mid=l+r>>1,tot=0,st=i;
				while(st<=mid)
				{
					tot+=mid/st;
					st*=i;
				}
				if(tot>=cnt)
					now=mid,r=mid-1;
				else
					l=mid+1;
			}
			ans=max(ans,now);
		}
		if(p>=1)
			ans=max(ans,p);
		cout<<ans<<endl;
	}
	return 0;
}


