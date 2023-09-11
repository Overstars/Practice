#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll a[maxn],d[maxn][20],pos[maxn][20],lg[maxn];
void init(ll a[],int n)
{//d[i][j]表示以i为起点,2^j长度的最值
	for(int i=1;i<=n;i++)
	{
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
		d[i][0]=a[i];
		pos[i][0]=i;
	}
	for(int j=1;(1<<j)<=n;j++)//枚举长度
		for(int i=1;i+(1<<j)-1<=n;i++)//枚举起点,倍增+DP
		{
			d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
			pos[i][j]=(d[i][j-1]>=d[i+(1<<(j-1))][j-1]?pos[i][j-1]:pos[i+(1<<(j-1))][j-1]);
		}
}
int rmq(int l,int r,bool p)
{
	int k=lg[r-l+1];
	if(p)
	{
		if(d[l][k]>=d[r-(1<<k)+1][k])
			return pos[l][k];
		else
			return pos[r-(1<<k)+1][k];
	}
	return max(d[l][k],d[r-(1<<k)+1][k]);
}
ll suf[maxn],stk[maxn],top=0;
ll sum[maxn];
vector<int>G[maxn];
void dfs(int x,int fa)
{
	sum[x]+=(fa-x)*a[x];
	for(int &v:G[x])
	{
		sum[v]+=sum[x];
		dfs(v,x);
	}
}
ll query(int l,int r)//暴力
{
	int p=rmq(l,r,1);
//	printf("p = %d,",p);
	ll ret=(r-p+1)*a[p]+sum[l]-sum[p];
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,qq,u,v;
	cin>>n>>qq;
	for(int i=1;i<=n;i++)
		cin>>a[i],suf[i]=n+1;
	for(int i=n;i>=1;i--)
	{
		while(top&&a[stk[top]]<=a[i])
			top--;
		if(top)
			suf[i]=stk[top];
		stk[++top]=i;
		G[suf[i]].push_back(i);
	}
	init(suf,n);
	dfs(n+1,n+1);
	ll ans=0;
	while(qq--)
	{
		cin>>u>>v;
		int l=1+(u^ans)%n,r=(v^(ans+1))%(n-l+1)+l;
//		cout<<"l = "<<l<<", r = "<<r<<endl;
		ans=query(l,r);
		cout<<ans<<endl;
	}
	return 0;
}
/*
 *强行在线
 *暴力rmq不行啊,会被卡成O(qn)的
 *能不能把每个查询优化成log
 *单调递减栈求出来a[i]后面第一个大于a[i]的位置
 *对每个位置预处理倍增数组,1,2,4...不太行
 *线段树求出[l,r]区间内第一个suf值>r的位置,即为后段最大值
 *这个位置即为区间最值第一次出现的位置
 *每一个点的跳转都是唯一的,可以看作以n+1为根的一棵树
 *在树上查询前缀和
*/
//int main1()
//{
//	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	#ifdef DEBUG
//		freopen("input.in", "r", stdin);
//	//	freopen("output.out", "w", stdout);
//	#endif
//	int n,t,u,v;
//	read(n,t);
//	for(int i=1;i<=n;i++)
//		read(a[i]);
////	cin>>n>>t;
////	for(int i=1;i<=n;i++)
////		cin>>a[i];
////	init(n);
//	ll ans=0;
//	while(t--)
//	{
//		read(u,v);
////		cin>>u>>v;
//		int l=1+(u^ans)%n,q=1+(v^(ans+1))%(n-l+1);
//		ans=0;
////		for(int i=0;i<q;i++)
////			ans+=rmq(l,l+i);
//		printf("%lld\n",ans);
////		cout<<ans<<endl;
//	}
//	return 0;
//}


