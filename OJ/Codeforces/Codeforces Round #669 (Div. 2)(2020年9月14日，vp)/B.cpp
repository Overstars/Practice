//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
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
int a[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1,greater<int>());
		int pos=2;
		ll G=a[1],M;
		while(pos<n)
		{
			M=G=__gcd(G,(ll)a[pos-1]);
			vector<ll>f;
			for(ll i=M;i>=2;i--)
				if(M%i==0)
					f.push_back(i);
			bool ok=0;
			for(ll &x:f)
			{
				for(ll i=pos;i<=n;i++)
				{
					if(a[i]%x==0)
					{
						swap(a[i],a[pos++]);
						ok=1;
					}
				}
				if(ok)
					break;
			}
			if(!ok)//gcd=1
				break;
		}
		for(int i=1;i<=n;i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}
/*
100
4
36 9 3 4
 */

