//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=5e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
signed main(int argc, char const *argv[])
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
		cin>>n>>k;
		int tot=0,ok=1;
		map<int,int>mp;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]<1||a[i]>k)
				ok=0;
		}
		vector<bool>f(n+1,false);
		for(int i=1;i<=n;i++)
		{
			if(mp[a[i]]==0)
				tot++;
			mp[a[i]]++;
			if(i>k)
			{
				if(--mp[a[i-k]]==0)
					tot--;
			}
			if(cnt==k&&i>k)
				f[i]=f[i-k];
			else if(cnt==i)
				f[i]=1;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
	return 0;
}


