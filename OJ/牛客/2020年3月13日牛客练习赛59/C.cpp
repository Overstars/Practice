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
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
//		ll lim=max(min(a/2,b/3),min(a/4,b));
		if(a>=4*b)
			cout<<b<<endl;
		else if(2*b>=3*a)
			cout<<a/2<<endl;
		else{
			ll x=(4*b-a)/10,y=(3*a-2*b)/10;
		}
		cout<<(a+b)/5<<endl;
//			cout<<max((4*b-a)/10+(3*a-2*b)/10,lim)<<endl;
//		cout<<max(0ll,(4*b-a)/10)+max(0ll,(3*a-2*b)/10)<<endl;
	}
	return 0;
}


