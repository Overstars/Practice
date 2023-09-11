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
ll t[maxn],a[maxn],b[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,k,ca=0,cb=0;
	cin>>n>>k;
	priority_queue<ll,vector<ll>,greater<ll> >both,aa,bb;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>a[i]>>b[i];
		if(a[i])
			ca++;
		if(b[i])
			cb++;
		if(a[i]&&b[i])
			both.push(t[i]);
		else if(a[i])
			aa.push(t[i]);
		else if(b[i])
			bb.push(t[i]);
	}
	if(ca<k||cb<k)
		return cout<<-1<<endl,0;
	ll na=0,nb=0,ans=0;
	while(na<k||nb<k)
	{
		if(na<k&&nb<k)
		{
			if(!aa.empty()&&!bb.empty())
			{
				if(!both.empty()&&both.top()<aa.top()+bb.top())
				{
					ans+=both.top();
					both.pop();
				}
				else{
					ans+=aa.top()+bb.top();
					aa.pop();
					bb.pop();
				}
			}
			else{
				ans+=both.top();
				both.pop();
			}
			na++,nb++;
		}
		else if(na<k)
		{
			if(!aa.empty()&&!both.empty())
			{
				if(aa.top()<both.top())
				{
					ans+=aa.top();
					aa.pop();
				}
				else{
					ans+=both.top();
					both.pop();
					nb++;
				}
			}
			else if(!aa.empty())
			{
				ans+=aa.top();
				aa.pop();
			}
			else{
				ans+=both.top();
				both.pop();
				nb++;
			}
			na++;
		}
		else{
			if(!bb.empty()&&!both.empty())
			{
				if(bb.top()<both.top())
				{
					ans+=bb.top();
					bb.pop();
				}
				else{
					ans+=both.top();
					both.pop();
					na++;
				}
			}
			else if(!bb.empty())
			{
				ans+=bb.top();
				bb.pop();
			}
			else{
				ans+=both.top();
				both.pop();
				na++;
			}
			nb++;
		}
//		printf("ans=%lld\n",ans);
	}
	cout<<ans<<endl;
	return 0;
}


