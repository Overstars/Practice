//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
#define ff first
#define ss second
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
struct edge
{
	int u,v;
	ll w;
//	bool operator < (const edge &b)
//	{
//		if(u==b.u)
//			return v<b.v;
//		return u<b.u;
//	}
//	bool operator == (const edge &b)
//	{
//		return (u==b.u)&&(v==b.v);
//	}
};
ll debt[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,u,v;
	ll w;
	vector<edge>e1,e2;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		debt[u]+=w;
		debt[v]-=w;
//		e1.push_back({u,v,w});
	}
//	sort(e1.begin(),e1.end());
//	for(int i=0;i<m;i++)
//	{
//		if(i==0||e2[e2.size()-1]!=e1[i])
//			e2.push_back(e1[i]);
//		else
//			e2[e2.size()-1].w+=e1[i].w;
//	}
//	sort(e2.begin(),e2.end(),[](const edge &a,const edge &b){
//			return a.w<b.w;
//		});
//	int dec=0;
//	if(e2.size()>2)
//		dec=e2[e2.size()-2].w;
//	cout<<e2.size()<<endl;
	vector<int>out,in;
	for(int i=1;i<=n;i++)
	{
		if(debt[i]>0)
			out.push_back(i);
		else if(debt[i]<0)
			in.push_back(i),debt[i]=-debt[i];
	}
//	for(int &x:out)
//		cout<<x<<' ';
//	cout<<endl;
//	for(int &x:in)
//		cout<<x<<' ';
//	cout<<endl;
	for(int i=0,j=0;i<out.size()&&j<in.size();i++)
	{
		u=out[i],v=in[j];
//		printf("%d->%d\n",u,v);
		while(debt[u]>=debt[v])
		{
			e2.push_back({u,v,debt[v]});
			debt[u]-=debt[v];
			if(j+1>=in.size())
				break;
			j++;
			v=in[j];
		}
		if(debt[u]>0)
		{
			e2.push_back({u,v,debt[u]});
			debt[v]-=debt[u];
		}
	}
	cout<<e2.size()<<endl;
	for(auto &e:e2)
		cout<<e.u<<' '<<e.v<<' '<<e.w<<endl;
	return 0;
}
/*
 *这题洛谷翻译着实坑爹
*/
/*
3 2
1 2 10
2 3 5
*/

