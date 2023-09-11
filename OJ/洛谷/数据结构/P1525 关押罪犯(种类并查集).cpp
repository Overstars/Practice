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
struct node
{
	int u,v,w;
	node(int u,int v,int w):
		u(u),v(v),w(w){}
};
int fa[maxn];
int findfa(int x)
{
	if(x!=fa[x])
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
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v,w;
	cin>>n>>m;
	for(int i=1;i<=2*n;i++)
		fa[i]=i;
	vector<node>vec;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		vec.push_back(node(u,v,w));
	}
	sort(vec.begin(),vec.end(),[](const node &a,const node &b){
			return a.w>b.w;
		});
	int ans=0;
	for(auto &x:vec)
	{
		if(findfa(x.u)==findfa(x.v))//之前此二人已经被分到同一监狱
		{
			ans=x.w;
			break;
		}
		Merge(x.u,x.v+n);
		Merge(x.u+n,x.v);
	}
	cout<<ans<<endl;
	return 0;
}


