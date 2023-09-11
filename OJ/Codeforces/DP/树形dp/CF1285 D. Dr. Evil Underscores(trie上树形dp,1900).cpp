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
int trie[maxn][2],siz=1;
int a[maxn];
ll ans=(1ll<<31);
ll dfs(int k,int l,int r)
{
	if(l>r||k<0)//没有或只有一个
		return 0;
	int p=l;
	for(int i=l;i<=r;i++)
	{
		if(a[i]&(1ll<<k))
			swap(a[p++],a[i]);
	}//a[l,p-1]的k位为1,a[p,r]的k位为0
//	fprintf(stderr,"k=%d,[%d,%d],p=%d\n",k,l,r,p);
	if(p==l||p==r+1)//该位全都一样,异或之后都为0
		return dfs(k-1,l,r);
	ll val=(1ll<<k)+min(dfs(k-1,l,p-1),dfs(k-1,p,r));//尽量使得高位最小
//	fprintf(stderr,"k=%d,val=%d\n",k,val);
	return val;
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
	cout<<dfs(30,1,n)<<endl;
	return 0;
}
/*
 * 2021-04-12-21.04.26
 * 如果某一位对于所有的数都为1/0,那么这一位必定无贡献
 * 因为可以让所有的数字异或之后该位为0
 * 否则的话这一位必定让一部分为0,另一部分为1
 * 因为要使异或最大值最小
 * 如果你假设最小最大值这一位为1,那么为0那一部分不必再看了
 * 似乎可以分治,从低位向高位dfs,因为高位起决定性作用
 * 001
 * 010
 * 101
*/
