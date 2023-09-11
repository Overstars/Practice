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
#define DEBUG////<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct BinaryIndexedsTree
{
	#define lowbit(x) ((x) & -(x))
	using type = long long;
	int n;
	type a[maxn],c[maxn];
	void modify(int pos,type val)
	{
		for(int i=pos;i<=n;i+=lowbit(i))
			c[pos]=max(c[pos],val);
	}
	type query(int l,int r)
	{
		if(l==r)
			return a[l];
		if(r-lowbit(r)>l)
			return max(c[r],query(l,r-lowbit(r)));
		return max(a[r],query(l,r-1));
	}
} bit;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("P3865_1.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int m,l,r;
	cin>>bit.n>>m;
	for(int i=1;i<=bit.n;i++)
		cin>>bit.a[i],bit.modify(i,bit.a[i]);
	while(m--)
	{
		cin>>l>>r;
		cout<<bit.query(l,r)<<'\n';
	}
	return 0;
}
/*
 * 2021-07-25-15.25.38
 * C:\Users\dell\Desktop\C++\OJ\洛谷\数据结构\P3865 【模板】ST表(树状数组).cpp
 *
*/

