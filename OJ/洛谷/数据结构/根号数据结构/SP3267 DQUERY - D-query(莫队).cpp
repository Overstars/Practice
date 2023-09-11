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
int a[maxn],cnt[maxn*10],pos[maxn],res=0,ans[maxn<<1];
struct ques
{
	int l,r,k;
} q[maxn<<1];
void add(int x)
{
	if(cnt[a[x]]==0)
		res++;
	cnt[a[x]]++;
}
void sub(int x)
{
	if(cnt[a[x]]==1)
		res--;
	cnt[a[x]]--;
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
	cin>>n;
	int siz=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[i]=i/siz;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>q[i].l>>q[i].r;
		q[i].k=i;
	}
	sort(q,q+m,[](const ques &a,const ques &b){
			return (pos[a.l]^pos[b.l])?pos[a.l]<pos[b.l]:((pos[a.l]&1)?a.r<b.r:a.r>b.r);
		});//奇偶排序
	int l=1,r=0;
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
		ans[q[i].k]=res;
	}
	for(int i=0;i<m;i++)
		cout<<ans[i]<<endl;
	return 0;
}


