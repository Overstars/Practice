//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
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
int a[maxn],d[maxn],cost[maxn];
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t;
//	scanf("%d",&t);
	cin>>t;
	while(t--)
	{
		int n,mc=inf;
//		scanf("%d",&n);
		cin>>n;
		for(int i=1;i<=n;i++)
//			scanf("%d",&a[i]);
			cin>>a[i];
		for(int i=1;i<=n;i++)
//			scanf("%d",&d[i]);
			cin>>d[i];
		map<int,int>mp;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=100)
				cost[i]=0;
			else
				cost[i]=(100/a[i]-((100%a[i])?0:1))*d[i];//花费时间
			mc=min(mc,cost[i]);
			mp[cost[i]]++;
		}
//		printf("%.15f\n",(2*n-mp[mc])/(2.0*n));
		cout<<setiosflags(ios::fixed)<<setprecision(30);
		cout<<((2*n-mp[mc])/(2.0*n))<<endl;
	}
	return 0;
}


