//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=3e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int fa[maxn];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool query(int x,int y)
{
	return findfa(x)==findfa(y);
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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,op,x,y,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n*3;i++)
		fa[i]=i;
	for(int i=1;i<=k;i++)
	{
		cin>>op>>x>>y;
		if(x>n||y>n)
		{
			ans++;
			continue;
		}
		if(x==y)
		{
			if(op==2)
				ans++;
			continue;
		}
		if(op==1)//同类
		{
			if(query(x,y+n)||query(y,x+n))//存在捕食关系
				ans++;
			else{
				Merge(x,y);
				Merge(x+n,y+n);
				Merge(x+2*n,y+2*n);
			}
		}
		else{
			if(query(x,y)||query(x+2*n,y))//同类,x被y吃
				ans++;
			else{
				Merge(x,y+2*n);//x是y的天敌
				Merge(x+n,y);//x的食物和y是同类
				Merge(x+2*n,y+n);//x的天敌是y的食物
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *两个动物只有捕食,被捕食,同类的关系
*/

