#include<bits/stdc++.h>
#define re register
using namespace std;
typedef long long ll;
const int maxn=1e7+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
int p[maxn],fa[maxn],ls[maxn],rs[maxn];
int stk[maxn],top=0;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	read(n);
	for(re int i=1;i<=n;i++)
		read(p[i]);
	for(re int i=1;i<=n;i++)//插入节点u
	{
		while(top&&p[stk[top]]>p[i])
			ls[i]=stk[top--];//从下到上遍历右链,这里弹出来的都是要作为u左子树滴
		fa[i]=stk[top];//x.w小于等于u.w,这里栈顶即为x,u作为x右儿子
		fa[ls[i]]=i;//x原来的左子树作为u的左子树
		if(fa[i])//u作为x的右儿子,fa[i]
			rs[fa[i]]=i;
		stk[++top]=i;//u变为右链的末端,入栈
	}
	ll ansl=ls[1]+1,ansr=rs[1]+1;
	for(ll i=2;i<=n;i++)
		ansl^=i*(ls[i]+1),ansr^=i*(rs[i]+1);
	printf("%lld %lld\n",ansl,ansr);
	return 0;
}
/*
 *以下标为键值k,权值为w,k满足二叉树性质,w满足堆性质
 *先按k排序,逐个插入节点
 *则当前插入节点u,则一定在之前插入节点右面
 *从下向上遍历当前树的右链(从根节点一路向右),设遍历节点为x
 *若找到x.w<u.w,则将u作为x的右儿子,原x的右子树作为u的左子树
 *可以i用单调栈维护右链
 */


