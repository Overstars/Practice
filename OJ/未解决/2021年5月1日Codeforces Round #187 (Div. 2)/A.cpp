//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
int a[maxn],b[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t=1,n;
//	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i];
		map<int,int> have,mp,mp2;
		for(int i=1;i<=n;i++)
		{
			have[a[i]]++;
			if(a[i]!=b[i])
				mp[b[i]]++;//所有的b[i]都可以被开
			else
				mp2[b[i]]++;//不能自己开自己
		}
		int ans=0;
		for(int i=1;i<=1000;i++)
		{
			if(mp[i]+mp2[i]>=2)
			{
				have[i]=0;
			}
			else if(mp[i])
			{
				have[i]=0;
			}
			else if(mp2[i]&&have[i]>0)
			{
				have[i]=1;//自己不能被开
			}
			ans+=have[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
 * 2021-05-01-14.57.29
*/

