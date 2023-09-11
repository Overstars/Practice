//#pragma comment(linker, "/STACK:102400000,102400000")
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
ll a[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll t,n,x,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		ll MAX=0,rec=0;
		map<ll,ll>mp;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(k-a[i]%k<k)
			{
				mp[k-a[i]%k]++;
				if(MAX<mp[k-a[i]%k])
				{
					MAX=mp[k-a[i]%k];
					rec=k-a[i]%k;
				}
				else if(MAX==mp[k-a[i]%k])
					rec=max(rec,k-a[i]%k);
			}
		}
//		printf("rec=%lld,MAX=%lld\n",rec,MAX);
		if(!MAX)
			cout<<0<<endl;
		else{
			cout<<rec+1+(MAX-1)*k<<endl;
		}
	}
	return 0;
}


