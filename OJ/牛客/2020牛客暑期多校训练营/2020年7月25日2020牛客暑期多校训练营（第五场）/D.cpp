//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=505,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn],d[maxn],g[maxn];
int get(int n)
{
	fill(g, g+n, INF);
    int ret=-1;
    for(int i=0; i<n; i++)
    {
        int j = lower_bound(g, g+n, a[i]) - g;
        d[i] = j+1;
        if(ret<d[i])
            ret=d[i];
        g[j] = a[i];
    }
	return ret;
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int tmp=a[0];
		for(int j=1;j<n;j++)
			a[j-1]=a[j];
		a[n-1]=tmp;
		ans=max(ans,get(n));
	}
	cout<<n-ans<<endl;
	return 0;
}


