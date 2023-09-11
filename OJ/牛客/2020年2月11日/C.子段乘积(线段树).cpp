#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5,inf=0x3f3f3f3f,mod=998244353;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
ll tree[maxn<<2],a[maxn];
void pushup(int rt)
{
	tree[rt]=(tree[rt<<1]*tree[rt<<1|1])%mod;
}
void build(int rt,int l,int r)
{
	if(l==r)
	{
		tree[rt]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
ll query(int rt,int nst,int ned,int qst,int qed)
{
	if(qst>ned||qed<nst)
		return 1;
	if(qst<=nst&&ned<=qed)
		return tree[rt];
	int mid=nst+ned>>1;
	return query(rt<<1,nst,mid,qst,qed)*query(rt<<1|1,mid+1,ned,qst,qed)%mod;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	ll ans=0;
	for(int i=k;i<=n;i++)
		ans=max(ans,query(1,1,n,i-k+1,i));
	cout<<ans<<endl;
	return 0;
}


