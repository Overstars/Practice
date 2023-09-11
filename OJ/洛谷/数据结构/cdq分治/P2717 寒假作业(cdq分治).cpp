//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int wtf[maxn],sum[maxn];
ll cdq(int l,int r)
{
	if(l==r)
		return (ll)wtf[l]>=0;
	int mid=(l+r)>>1;
	ll ret=cdq(l,mid)+cdq(mid+1,r);
	sum[mid]=wtf[mid],sum[mid+1]=wtf[mid+1];
	for(int i=mid-1;i>=l;i--)//前半部分的后缀和
		sum[i]=sum[i+1]+wtf[i];
	for(int i=mid+2;i<=r;i++)//后半部分的前缀和
		sum[i]=sum[i-1]+wtf[i];
	sort(sum+l,sum+mid+1);//升序
//	sort(sum+mid+1,sum+r+1);
//	for(int i=l,j=r;i<=mid;i++)
//	{
//		while(sum[i]+sum[j]>=0&&j>mid)
//			j--;
//		ret+=r-j;
//	}
	sort(sum+mid+1,sum+r+1,greater<int>());//降序
	for(int i=mid+1,j=l;i<=r;i++)
	{
		while(sum[i]+sum[j]<0&&j<=mid)//拼接起来≥0
			j++;
		ret+=mid-j+1;
	}
	return ret;
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k;
//	scanf("%d%d",&n,&k);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
//		scanf("%d",&wtf[i]);
		cin>>wtf[i];
		wtf[i]-=k;
	}
//	printf("%lld\n",cdq(1,n));
	cout<<cdq(1,n)<<endl;
	return 0;
}
/*
5 4
1 2 3 4 5
7 4
5 0 4 3 4 8 9
*/

