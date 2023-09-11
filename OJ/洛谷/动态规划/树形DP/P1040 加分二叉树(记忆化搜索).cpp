//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=105,inf=0x3f3f3f3f,mod=1000000007;
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
ll ans=0,root=0,a[maxn],rec[maxn][maxn],val[maxn][maxn];
ll dfs(int l,int r)
{
	if(l>r)
		return 1;
	if(val[l][r])
		return val[l][r];
	if(l==r)
	{
		rec[l][r]=l;
		return a[l];
	}
	ll ret=0,rt=0;
	for(int i=l;i<=r;i++)
	{//i作为根节点
		ll now=dfs(l,i-1)*dfs(i+1,r)+a[i];
		if(now>ret)
		{//区间根节点
			rt=i;
			ret=now;
		}
	}
	val[l][r]=ret;
	rec[l][r]=rt;
	return ret;
}
void show(int l,int r)
{
	if(l>r)
		return;
	printf("%d ",rec[l][r]);
	show(l,rec[l][r]-1);
	show(rec[l][r]+1,r);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<dfs(1,n)<<endl;
	show(1,n);
	return 0;
}


