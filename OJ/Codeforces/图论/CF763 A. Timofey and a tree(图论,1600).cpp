#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG//<<setiosflags(ios::fixed)<<setprecision(9)
struct edge
{
	int u,v;
	edge(int u,int v):
		u(u),v(v){}
};
vector<edge>E;
int rec[maxn],col[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,u,v,tot=0;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		E.push_back(edge(u,v));
	}
	for(int i=1;i<=n;i++)
		cin>>col[i];
	for(auto &e:E)
	{
		if(col[e.u]!=col[e.v])
		{
			tot++;
			rec[e.u]++,rec[e.v]++;
		}
	}
	for(int i=1;i<=n;i++)
		if(rec[i]==tot)
		{
			cout<<"YES\n"<<i<<endl;
			exit(0);
		}
	cout<<"NO\n";
	return 0;
}
/*
 *给你一棵染色树,选择一个根节点
 *要求保证这个根节点子树上节点颜色相同
 *
 *所以分别统计*每个节点i*与相邻节点颜色不同的数量rec[i]
 *与树上总共相邻两点颜色不同的个数tot
 *所以符合要求的节点一定rec[i]=tot
 *因为根据要求,树上不同只一定发生在该节点周围
 */
