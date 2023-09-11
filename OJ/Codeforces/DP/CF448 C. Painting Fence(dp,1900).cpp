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
ll h[maxn];
ll dfs(int l,int r,ll x)
{//[l,r]区间内已经被涂掉了x高度
	if(l==r)
		return 1;
	ll m=INF,ret=r-l+1,ret2=0;//全部竖着涂
	for(int i=l;i<=r;i++)
		m=min(m,h[i]);//h[i]>x
	ret2=m-x;//横着涂
	int pos=l;
	for(int i=l;i<=r;i++)
	{
		if(h[i]==m)
		{
			ret2+=dfs(pos,i-1,m);
			pos=i+1;
		}
	}
	if(pos!=r+1)
		ret2+=dfs(pos,r,m);
	return min(ret,ret2);
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
		cin>>h[i];
	cout<<dfs(1,n,0)<<endl;
	return 0;
}
/*
 * 2021-04-11-17.31.11
 * 刷木板,可以竖着刷也可以横着刷,问最少刷几下
 * 横着涂肯定要尽量涂最高的,下面全是横着涂
*/

