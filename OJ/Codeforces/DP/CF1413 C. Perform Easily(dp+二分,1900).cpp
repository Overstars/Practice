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
int a[maxn],b[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cout<<endl;
	for(int i=1;i<=6;i++)
		cin>>a[i];
	sort(a+1,a+7);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	sort(b+1,b+n+1);
	ll ans=LLONG_MAX;
	set<int> st;
	set<int>::iterator it;
	for(int i=1;i<=n;i++)
		st.insert(b[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=6;j++)
		{//m=b[i]-a[j]作为最小值,其他b-a要在>=m情况下尽量小
			ll m=b[i]-a[j],M=m;//M为对应的最大值
			if(m>b[1]-a[1])//m不能作为合法最小值
				continue;
			for(int k=2;k<=6;k++)//b[i]-a[k]>=m
			{//对于每个k,求出对应的最大值,m+a[k]<=b[i]
				//但要求b[i]-a[i]尽量小,那么有b[i]-a[k+1]<m
				//否则使b[i]-a[k+1]是更优解
				//即m+a[k]<=b[i]<m+a[k+1],求出这个b[i]即可
				it=st.lower_bound(m+a[k]);
				if(it==st.begin())
					continue;
				it--;
				M=max(M,*it-a[k-1]);
			}
			it=st.end();//之后的只能减去a[6]
			M=max(M,*(--it)-a[6]);
			ans=min(ans,M-m);
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
 * 2021-04-23-11.28.22
 *
*/

