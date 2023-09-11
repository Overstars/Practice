#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
long long gcd(long long a,long long b)
{
	if(a<b)
		swap(a,b);
	long long r;
	while((r=a%b)){
		a=b;
		b=r;
	}
	return b;
}
int c[maxn],pos[maxn];
struct ques
{
	ll l,r,k;
} q[maxn];
ll res=0,ans[maxn][2],cnt[maxn];
inline void add(int x)
{
	cnt[c[x]]++;
	if(cnt[c[x]]>=2)
		res+=cnt[c[x]]*(cnt[c[x]]-1)/2-(cnt[c[x]]-1)*(cnt[c[x]]-2)/2;
}
inline void sub(int x)
{
	cnt[c[x]]--;
	if(cnt[c[x]]>=1)
		res+=cnt[c[x]]*(cnt[c[x]]-1)/2-(cnt[c[x]]+1)*(cnt[c[x]])/2;
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
	int n,m;
	cin>>n>>m;
	int siz=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		pos[i]=i/siz;
	}
	for(int i=0;i<m;i++)
	{
		q[i].k=i;
		cin>>q[i].l>>q[i].r;
	}
	sort(q,q+m,[](const ques &a,const ques &b){
		return (pos[a.l]^pos[b.l])?pos[a.l]<pos[b.l]:((pos[a.l]&1)?a.r<b.r:a.r>b.r);
	});//奇偶排序
	ll l=1,r=0;
	for(int i=0;i<m;i++)
	{
		while(l<q[i].l)
			sub(l++);
		while(l>q[i].l)
			add(--l);
		while(r>q[i].r)
			sub(r--);
		while(r<q[i].r)
			add(++r);
		if(l==r||res==0)
		{
			ans[q[i].k][0]=0;
			ans[q[i].k][1]=1;
			continue;
		}
		ll tot=(q[i].r-q[i].l+1)*(q[i].r-q[i].l)>>1;
		ll g=gcd(res,tot);
		ans[q[i].k][0]=res/g;
		ans[q[i].k][1]=tot/g;
	}
	for(int i=0;i<m;i++)
		cout<<ans[i][0]<<'/'<<ans[i][1]<<endl;
	return 0;
}


