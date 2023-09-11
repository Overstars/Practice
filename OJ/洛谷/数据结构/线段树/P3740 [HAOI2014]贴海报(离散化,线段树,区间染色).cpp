#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3005;
struct ele
{
	int l,r;
} a[1005];
struct node
{
	int color;
} tree[2005<<2];
inline void pushup(int root)
{
	if(tree[root<<1].color==tree[root<<1|1].color)//两个子区间颜色相同
		tree[root].color=tree[root<<1].color;
	else
		tree[root].color=-1;//杂色
}
void build(int root,int l,int r)
{
	if(l==r)
	{//无染色
		tree[root].color=0;
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	pushup(root);
}
inline void pushdown(int root)
{
	if(tree[root].color>0)//区间染色向下传递
		tree[root<<1].color=tree[root<<1|1].color=tree[root].color;
}
void modify(int root,int nst,int ned,int ust,int ued,int col)//将区间修改为col
{
	if(nst>ued||ust>ned)
		return;
	if(ust<=nst&&ned<=ued)
	{
		tree[root].color=col;
		return;
	}
	pushdown(root);
	int mid=(nst+ned)>>1;
	modify(root<<1,nst,mid,ust,ued,col);
	modify(root<<1|1,mid+1,ned,ust,ued,col);
	pushup(root);
}
bool vis[maxn];
int ans=0;
void query(int root,int nst,int ned)
{
	if(nst>ned)
		return;
	if(tree[root].color>0)//纯色区间
	{
		if(!vis[tree[root].color])
		{
			vis[tree[root].color]=1;
			ans++;
			return;
		}
	}
	if(nst==ned)
		return;
	pushdown(root);
	int mid=(nst+ned)>>1;
	query(root<<1,nst,mid);
	query(root<<1|1,mid+1,ned);
	pushup(root);
}
int t[maxn];
void discretization(int n)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		t[++cnt]=a[i].l;
		t[++cnt]=a[i].r;
		t[++cnt]=a[i].r+1;//防止离散化错误
	}
	sort(t+1,t+cnt+1);
	int m=unique(t+1,t+cnt+1)-t-1;//m为离散化后范围
	for(int i=1;i<=n;i++)
	{
		int l=lower_bound(t+1,t+m+1,a[i].l)-t;
		int r=lower_bound(t+1,t+m+1,a[i].r)-t;
		modify(1,1,m,l,r,i);//区间染色
	}
	query(1,1,m);
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i].l>>a[i].r;
	discretization(m);
	cout<<ans<<'\n';
	return 0;
}
/*
hack数据,添加r+1防止离散化损失
1
3
1 10
1 4
7 10
答案3
*/
