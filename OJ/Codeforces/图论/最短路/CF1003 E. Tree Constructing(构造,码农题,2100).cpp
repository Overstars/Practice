//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=4e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
vector<pii>ans;
bool ok=0;
int deg[maxn],tot=0,n,k;
void dfs(int x,int fa,int lim)
{
	if(ok||lim<=0)
		return;
	if(tot==n)
	{
		ok=1;
		return;
	}
	while(deg[x]<k&&tot<n)
	{
		ans.push_back(pii(x,++tot));
		deg[tot]=1;
		deg[x]++;
		dfs(tot,x,lim-1);
	}
	if(tot==n)
		ok=1;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int d;
	cin>>n>>d>>k;
//	if(n>=2&&k<=1)
//		return cout<<"NO"<<endl,0;
	for(int i=2;i<=d+1;i++)
	{
		deg[i]++,deg[i-1]++;
		ans.push_back(pii(i-1,i));
	}
	tot=d+1;//用了d+1个
	for(int i=2;i<=d;i++)
	{
		dfs(i,i,min(i-1,d+1-i));
	}
	if(tot==n)
		ok=1;
//	for(pii &i:ans)
//		cout<<i.ff<<' '<<i.ss<<endl;
	for(int i=1;i<=n;i++)
		if(deg[i]>k)
			ok=0;
	if(!ok)
		return cout<<"NO"<<endl,0;
	cout<<"YES"<<endl;
	for(pii &i:ans)
		cout<<i.ff<<' '<<i.ss<<endl;
	return 0;
}
/*
 *读完题就知道先构造出一条长度为d的链,消耗d+1个点
 *再把剩下的n-d-1个点贪心加上去
*/

