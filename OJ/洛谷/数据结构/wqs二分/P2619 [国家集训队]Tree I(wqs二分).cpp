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
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct edge
{
	int u,v,w,c;
	edge(){}
	edge(int u,int v,int w,int c):
		u(u),v(v),w(w),c(c){}
	bool operator <(const edge &y)
	{
		if(w!=y.w)
			return w<y.w;
		return c<y.c;//白边优先
	}
};
vector<edge>B,W;
int fa[maxn],cnt=0;
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
		fa[b]=a;
	else
		fa[a]=b;
	return 1;
}
int kruskal(int n,int k)
{//斜率k,每个白边附加权值为-k
	for(int i=1;i<=n;i++)
		fa[i]=i;//b=g(x)-kx
	int ans=0;
	vector<edge>E;
	E.insert(E.end(),W.begin(),W.end());
	for(auto &x:E)
		x.w-=k;
	E.insert(E.end(),B.begin(),B.end());
	sort(E.begin(),E.end());
	for(auto &e:E)
	{
//		printf("%d->%d,w=%d,c=%d\n",e.u,e.v,e.w,e.c);
		if(Merge(e.u,e.v))
		{
			ans+=e.w;
			n--;
			if(e.c==0)
				cnt++;
			if(n==1)
				return ans;
		}
	}
	return ans;
}
signed main(signed argc, char const *argv[])
{
//	#define DEBUG
	#ifdef DEBUG
		freopen("P2619_3", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,need,u,v,c,w;
	cin>>n>>m>>need;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w>>c;
		u++,v++;
		if(c==0)
			W.push_back(edge(u,v,w,c));
		else
			B.push_back(edge(u,v,w,c));
	}
	sort(W.begin(),W.end());
	sort(B.begin(),B.end());
	int l=-105,r=105,ans=-1,b,k;
	while(l<=r)
	{
		k=(l+r)>>1;//二分斜率
		cnt=0;
		b=kruskal(n,k);//白边附加值为mid时选择白边的数量
//		printf("k = %d, b = %d, x = %d\n",k,b,cnt);
		if(cnt<need)//b随着x增加单调递减
		{//g(x)=b+kx
			l=k+1;//增大斜率,使白边权变得更小
		}
		else{
			r=k-1;
			ans=b+k*need;//让b相同时仍能取到正确答案
		}
	}
//	if(ans==-1)
//	{
//		b=kruskal(n,k);//最后的斜率k,截距b
//		ans=b+k*need;
//	}
	cout<<ans<<endl;
	return 0;
}
/*
 * 2021-04-30-17.12.06
 * x为选择白边的数量,g(x)为生成树权值
 * 是一个凹函数
*/

