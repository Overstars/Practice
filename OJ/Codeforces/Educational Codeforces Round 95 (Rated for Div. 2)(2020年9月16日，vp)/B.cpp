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
ll a[maxn],loc[maxn];
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
	{//重排数组使k最大
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>loc[i];
		int k=0;
		for(int i=1;i<=n;i++)
		{
			if(loc[i])
				continue;
			int pos=i;
			for(int j=i+1;j<=n;j++)
			{
				if(loc[j])
					continue;
				if(a[pos]<a[j])
					pos=j;
			}
			if(a[pos]>a[i])
				swap(a[i],a[pos]);
		}
		for(int i=1;i<=n;i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}


