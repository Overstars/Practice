//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
struct Node
{
	int fa,ch[2];//
	int val,res;//res为异或结果
	bool lazy;//翻转
} spl[maxn];
inline void reverse(int x)
{//反转操作
	std::swap(spl[x].ch[0],spl[x].ch[1]);
	spl[x].lazy^=1;
}
inline bool ntroot(int x)
{//判断x是否为splay的根,不是则为真
	return spl[spl[x].fa].ch[0]==x||spl[spl[x].fa].ch[1]==x;
}//父节点的子节点没有x,说明x为splay的根
inline void pushdown(int x)
{//lazy下传
	if(spl[x].lazy)
	{
		if(spl[x].ch[0])
			reverse(spl[x].ch[0]);
		if(spl[x].ch[1])
			reverse(spl[x].ch[1]);
		spl[x].lazy=0;
	}
}
inline void pushup(int x)
{
	spl[x].res=spl[spl[x].ch[0]].res^spl[spl[x].ch[1]].res^spl[x].val;
}
void pushall(int x)
{//从上到下下传所有lazy标记
	if(ntroot(x))
		pushall(spl[x].fa);
	pushdown(x);
}
inline void rotate(int x)
{//一次旋转
	#define ident(x,f) (spl[f].ch[1]==x)
	//x是否为f的右儿子
	#define connect(x,f,s) (spl[spl[x].fa=f].ch[s]=x)
	//x与f建立父子关系,s=0为左儿子
	int fa=spl[x].fa,ffa=spl[fa].fa,k=indet(x,fa);
	connect(spl[x].ch[k^1],f,k);
	spl[x].fa=ffa;
	if(ntroot(f))
		spl[ffa].ch[ident(f,ffa)]=x;
	connect(f,x,k^1);
	pushup(f),pushup(x);
}
inline void splaying(int x)
{
	#define ident(x,f) (spl[f].ch[1]==x)
	pushall(x);//下传所有lazy
	while(ntroot(x))
	{
		int f=spl[x].fa,ffa=spl[f].fa;
		if(ntroot(f))
			ident(f,ffa)^ident(x,f)?rotate(x):rotate(f);
		rotate(x);
	}
}
inline void access(int x)
{
	for(int y=0;x;y=x,x=)
	{
		spl[x].ch[1]=y;//右儿子连上一个
	}
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif

	return 0;
}


