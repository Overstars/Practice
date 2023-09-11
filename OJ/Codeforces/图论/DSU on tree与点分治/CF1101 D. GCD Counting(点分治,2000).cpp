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
const int MAXN=200010;
int phi[MAXN+1],prime[MAXN+1],psize;//psize是素数的个数,prime[i]存着第i个素数
bool isprime[MAXN+1];
void getlist(void)
{
	memset(isprime,1,sizeof(isprime));
	psize=0;
	isprime[1]=false;
	phi[1]=1;
	for(int i=2;i<=MAXN;i++)
	{
		if(isprime[i])
			prime[++psize]=i,phi[i]=i-1;
		for(int j=1;j<=psize&&i*prime[j]<=MAXN;j++)
		{
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
int a[maxn],n;
vector<int>G[maxn],f[maxn];
set<int>fac[maxn];
int siz[maxn],maxp[maxn],root,sum=0;//重心root,当前大小sum
bool vis[maxn];
void getrt(int x,int fa)
{
	siz[x]=1,maxp[x]=0;//最大子树大小
	for(auto &v:G[x])
	{
		if(v==fa||vis[v])
			continue;
		getrt(v,x);
		siz[x]+=siz[v];
		maxp[x]=max(maxp[x],siz[v]);
	}
	maxp[x]=max(maxp[x],sum-siz[x]);
	if(maxp[x]<maxp[root])
		root=x;
}
int ans=0;
map<int,int> jud,res;//前面的子树检测
int getdist(int x,int fa,int p)
{//p因子在x子树所到最深深度
	if(a[x]%p)
		return 0;
	int ret=0;
	for(auto &v:G[x])
	{
		if(v==fa||vis[v])
			continue;
		ret=max(ret,getdist(v,x,p));
	}
	return ret+1;
}
void solve(int x,int p)
{//处理经过x的路径,多个log会T
//	for(auto &i:f[x])
//		jud[i]=0;
	int pre=0;
	for(auto &v:G[x])
	{
		if(vis[v])
			continue;
		int now=getdist(v,x,p);
		ans=max(ans,pre+now+1);
		pre=max(pre,now);
		//子树v上某一质因子最长路径
//		res.clear();
//		map<int,int>tmp;
//		for(auto &i:f[x])//枚举每个质因子
//			res[i]=getdist(v,x,i);
//		for(auto &i:res)//当前的
//			ans=max(ans,i.ss+jud[i.ff]+1);
//		for(auto &i:res)//加入到之前的因子
//			jud[i.ff]=max(jud[i.ff],i.ss);
	}
//	jud.clear();
}
void divide(int x)
{
	vis[x]=1;
	for(auto &i:f[x])
		solve(x,i);//处理所有因子经过x的路径
	for(auto &v:G[x])
	{
		if(vis[v])
			continue;
		maxp[root=0]=sum=siz[v];
		getrt(v,0);//处理子树v
		getrt(root,0);
		divide(root);
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	getlist();
//	cout<<psize<<endl;
	int u,v;
	read(n);
//	cin>>n;
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		if(a[i]>1)
			ans=1;
//		if(i>1&&a[1]==199999)
//			assert(a[i]==199999);
//		cin>>a[i];
		int tmp=a[i];
		if(!isprime[a[i]])
		for(int j=1;j<=psize&&prime[j]<=tmp;j++)
		{
			if(tmp%prime[j]==0)
			{
				f[i].push_back(prime[j]);
				while(tmp%prime[j]==0)
					tmp/=prime[j];
			}
		}
		if(tmp>1)
			f[i].push_back(tmp);
//		for(auto &x:f[i])
//		{
//			fac[i].insert(x);
////			cout<<x<<endl;
//		}
	}
//	sort(vv.begin(),vv.end());
	for(int i=1;i<n;i++)
	{
		read(u,v);
//		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	maxp[0]=sum=n;//置为最大值
	getrt(1,0);
	getrt(root,0);
	divide(root);
	printf("%d\n",ans);
//	cout<<ans<<endl;
	return 0;
}
/*
 * 2021-05-11-20.42.00
 * 直接跑树形dp空间会炸
 * 写了点分治发现好像多此一举...
 * 卡质因子分解,绝了
*/

