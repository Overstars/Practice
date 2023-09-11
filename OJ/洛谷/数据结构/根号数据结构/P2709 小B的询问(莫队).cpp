#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
struct ques
{
	int l,r,k;
} Q[maxn];
int a[maxn],pos[maxn];
ll ans[maxn],c[maxn],res=0;
void add(int x)
{
	c[a[x]]++;
	res+=c[a[x]]*c[a[x]]-(c[a[x]]-1)*(c[a[x]]-1);
}
void del(int x)
{
	c[a[x]]--;
	res+=c[a[x]]*c[a[x]]-(c[a[x]]+1)*(c[a[x]]+1);
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
	int n,m,k;
	cin>>n>>m>>k;
	int siz=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[i]=i/siz;
	}
	for(int i=0;i<m;i++)
	{
		cin>>Q[i].l>>Q[i].r;
		Q[i].k=i;
	}
	sort(Q,Q+m,[](const ques &a,const ques &b){
		return pos[a.l]==pos[b.l]?a.r<b.r:pos[a.l]<pos[b.l];
	});
	int l=1,r=0;
	for(int i=0;i<m;i++)
	{
		while(l<Q[i].l)
			del(l++);
		while(l>Q[i].l)
			add(--l);
		while(r<Q[i].r)
			add(++r);
		while(r>Q[i].r)
			del(r--);
		ans[Q[i].k]=res;
	}
	for(int i=0;i<m;i++)
		cout<<ans[i]<<endl;
	return 0;
}


