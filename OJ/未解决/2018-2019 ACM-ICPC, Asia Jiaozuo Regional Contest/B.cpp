//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
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
int sum[maxn],a[maxn];
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
		for(int i=2;i<=n;i++)
		{
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];//sum[i]=1->i
		}
		int l=0,r=n+1,cnt=0,ans=0;
		int pre=0,aft=0,pc=0,ac=0;
//		cout<<0;
		for(int i=1;i<=n;i++)
		{
			if(i&1)
			{
				l++;
				ans+=sum[l]*pc-pre;
				ans+=aft-sum[l]*ac;
				pc++;//前面
				pre+=sum[l];
			}
			else{
				r--;
				ans+=aft-sum[r]*ac;
				ans+=sum[r]*pc-pre;
				aft+=sum[r];
				ac++;//
			}
			if(i<n)
				cout<<ans<<' ';
			else
				cout<<ans<<endl;
		}
//		cout<<endl;
	}
	return 0;
}
/*
 * 2021-04-17-14.08.28
*/

