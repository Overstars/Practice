//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn],pos[maxn],sum[maxn],k;
struct ques
{
	int l,r,id;
	bool operator <(const struct ques &b){//按l排序
		return pos[l]==pos[b.l]?r<b.r:pos[l]<pos[b.l];
	}
} Q[maxn];
ll ans[maxn],res=0,cnt[maxn]={0};
void add(int x)
{
	res+=cnt[k^sum[x]];
	cnt[sum[x]]++;
}
void del(int x)
{
	cnt[sum[x]]--;
	res-=cnt[k^sum[x]];
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m>>k;
	int siz=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];//异或前缀和
		pos[i]=i/siz;
	}
	for(int i=0;i<m;i++)
		cin>>Q[i].l>>Q[i].r,Q[i].id=i,Q[i].l--;
	sort(Q,Q+m);
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
		ans[Q[i].id]=res;
	}
	for(int i=0;i<m;i++)
		cout<<ans[i]<<endl;
	return 0;
}
/*
 *询问区间里面有多少个子区间的异或值为k
 *瞄了眼题解才知道要用前缀和...
 *sum[i-1]^sum[j]=k,说明[i,j]异或和=k
 *对于每对l与r,统计[l-1,r]加入x新产生的k^sum[x]对数
 *加入:先统计贡献,后修改值
*/

