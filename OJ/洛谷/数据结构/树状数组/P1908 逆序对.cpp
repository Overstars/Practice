#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
#define lowbit(x) (x&(-x))
const int maxn=500005;
ll c[maxn];
//ll rak[maxn];
//struct node
//{
//	int v,id;
//	bool operator < (const node a)const
//	{
//		return v<a.v;
//	}
//} a[maxn];
//void discre(int n)
//{
//	for(int i=1;i<=n;i++)
//		a[i].id=i;
//	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)
//		rak[a[i].id]=i;
//}
ll a[maxn],t[maxn];
void discre2(int n)
{
	for(int i=1;i<=n;i++)
		t[i]=a[i];
	sort(t+1,t+n+1);
	int m=unique(t+1,t+n+1)-t-1;//ÀëÉ¢»¯ºó·¶Î§
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(t+1,t+m+1,a[i])-t;
}
void update(int x,ll num,int n)
{
	while(x<=n)
	{
		c[x]+=num;
		x+=lowbit(x);
	}
}
ll query(int x)
{
	ll sum=0;
	while(x)
	{
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}
int main()
{
//	freopen("P1908 (1).in","r",stdin);
	int n;
	ll ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	discre2(n);
	for(int i=n;i;i--)
	{
		ans+=query(a[i]-1);
		update(a[i],1,n);
	}
	printf("%lld\n",ans);
	return 0;
}
