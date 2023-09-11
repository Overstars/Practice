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
struct block
{
	int l,r,id;
}Q[maxn];
int a[maxn],pos[maxn];
ll ans[maxn],c[maxn*5],res;
void add(int x)
{//
	res-=c[a[x]]*c[a[x]]*a[x];
	c[a[x]]++;
	res+=c[a[x]]*c[a[x]]*a[x];
}
void del(int x)
{
	res-=c[a[x]]*c[a[x]]*a[x];
	c[a[x]]--;
	res+=c[a[x]]*c[a[x]]*a[x];
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,q;
	cin>>n>>q;
	int siz=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[i]=i/siz;
	}
	for(int i=1;i<=q;i++)
		cin>>Q[i].l>>Q[i].r,Q[i].id=i;
	sort(Q+1,Q+q+1,[](const block &x,const block &y){
			return pos[x.l]==pos[y.l]?x.r<y.r:pos[x.l]<pos[y.l];
		});
	int l=1,r=0;
	for(int i=1;i<=q;i++)
	{
		while(l<Q[i].l)
			del(l++);
		while(l>Q[i].l)
			add(--l);
		while(r>Q[i].r)
			del(r--);
		while(r<Q[i].r)
			add(++r);
		ans[Q[i].id]=res;
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<'\n';
	return 0;
}
/*
 *2021-04-02-21.24.26
 *[l,r]区间询问,输出权值*出现次数的平方的和
*/

