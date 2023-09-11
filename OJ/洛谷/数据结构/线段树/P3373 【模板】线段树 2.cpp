#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
struct node
{
	ll val,add,mul;
} tree[maxn<<2];
ll a[maxn],p;
inline void pushup(int root)
{
	tree[root].val=(tree[root<<1].val+tree[(root<<1)+1].val)%p;
}
void build(int root,ll arr[],int l,int r)
{
	tree[root].add=0;
	tree[root].mul=1;
	if(l==r)
		tree[root].val=arr[l];
	else{
		int mid=l+r>>1;
		build(root<<1,arr,l,mid);
		build((root<<1)+1,arr,mid+1,r);
		pushup(root);
	}
}
inline void pushdown(int root,int l,int r)
{
	int mid=l+r>>1;
//子节点的值=原值*父节点mul+父节点add*区间长度
	tree[root<<1].val=((tree[root<<1].val*tree[root].mul)%p+(tree[root].add*(mid-l+1))%p)%p;//更新子节点的值
	tree[(root<<1)+1].val=((tree[(root<<1)+1].val*tree[root].mul)%p+(tree[root].add*(r-mid))%p)%p;
//维护子节点的lazyTag,子节点mul=与父结点mul累乘
	tree[root<<1].mul=(tree[root<<1].mul*tree[root].mul)%p;
	tree[(root<<1)+1].mul=(tree[(root<<1)+1].mul*tree[root].mul)%p;
//子节点add=add*父节点mul+父节点add
	tree[root<<1].add=((tree[root<<1].add*tree[root].mul)%p+tree[root].add)%p;
	tree[(root<<1)+1].add=((tree[(root<<1)+1].add*tree[root].mul)%p+tree[root].add)%p;

	tree[root].add=0;
	tree[root].mul=1;
}
void update(int root,int nst,int ned,int ust,int ued,ll addnum,ll mulnum)
{
	if(nst>ued||ust>ned)
		return;
	if(ust<=nst&&ned<=ued)
	{
		tree[root].val=((tree[root].val*mulnum)%p+(addnum*(ned-nst+1))%p)%p;
		tree[root].add=(tree[root].add*mulnum+addnum)%p;
		tree[root].mul=(tree[root].mul*mulnum)%p;
		return;
	}
	pushdown(root,nst,ned);
	int mid=nst+ned>>1;
	update(root<<1,nst,mid,ust,ued,addnum,mulnum);
	update((root<<1)+1,mid+1,ned,ust,ued,addnum,mulnum);
	pushup(root);
}
ll query(int root,int nst,int ned,int qst,int qed)
{
	if(qst>ned||nst>qed)
		return 0;
	if(qst<=nst&&ned<=qed)
	{
		return tree[root].val%p;
	}
	pushdown(root,nst,ned);
	int mid=nst+ned>>1;
	return (query(root<<1,nst,mid,qst,qed)+query((root<<1)+1,mid+1,ned,qst,qed))%p;
}
int main()
{
//	freopen("P3373.in","r",stdin);
	int n,m;
	scanf("%d%d%lld",&n,&m,&p);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,a,1,n);
//	cout<<"build finished"<<endl;
	while(m--)
	{
		int flag,x,y;
		ll k;
		scanf("%d",&flag);
		if(flag==1)
		{
			scanf("%d%d%lld",&x,&y,&k);
//			cout<<"flag="<<flag<<endl;
			update(1,1,n,x,y,0,k);
//			cout<<"flag1"<<endl;
		}
		else if(flag==2)
		{
			scanf("%d%d%lld",&x,&y,&k);
//			cout<<"flag="<<flag<<endl;
			update(1,1,n,x,y,k,1);
//			cout<<"flag2"<<endl;
		}
		else{
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,1,n,x,y)%p);
		}
	}
	return 0;
}
