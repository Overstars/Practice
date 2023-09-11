#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100005;
typedef long long ll;
struct SegTreeNode
{
	ll val;
	ll lazyTag;//延迟标记:储存节点的修改情况
	SegTreeNode()
	{
		val=0;
		lazyTag=0;
	}
} segTree[maxn<<2];//完全二叉树(有没用到的节点),一倍可能炸
inline void pushup(int root)
{
	segTree[root].val=segTree[root*2].val+segTree[root*2+1].val;
}
inline void pushdown(int root,int l,int r)//当前节点标志域向孩子节点传递
{//root为当前节点下标
	if(segTree[root].lazyTag)
	{
		segTree[root*2].lazyTag+=segTree[root].lazyTag;
		segTree[root*2+1].lazyTag+=segTree[root].lazyTag;
		int mid=(l+r)>>1;
		segTree[root*2].val+=segTree[root].lazyTag*(mid-l+1);
		segTree[root*2+1].val+=segTree[root].lazyTag*(r-mid);
		segTree[root].lazyTag=0;//消掉该点的标记
	}
}
void build(int root,ll arr[],int ist,int ied)
{//当前根节点
	segTree[root].lazyTag=0;
	if(ist==ied)//叶子节点
		segTree[root].val=arr[ist];
	else
	{
		int mid=(ist+ied)>>1;
		build(root*2,arr,ist,mid);
		build(root*2+1,arr,mid+1,ied);
		pushup(root);
	}
}
void update(int root,int nst,int ned,int ust,int ued,ll num)
{//nst:当前区间,ust:更新区间
	if(ust>ned||ued<nst)
		return;
	if(ust<=nst&&ned<=ued)//子区间更新完成,
	{
		segTree[root].lazyTag+=num;//更新值记录在lazyTag
		segTree[root].val+=(ned-nst+1)*num;
		return;
	}
//	printf("l=%d,r=%d\n",nst,ned);
	pushdown(root,nst,ned);//标记向下传递
	int mid=(nst+ned)>>1;
//	cout<<"HERE1"<<endl;
//	system("pause");
	update(root*2,nst,mid,ust,ued,num);
//	cout<<"HERE2"<<endl;
	update(root*2+1,mid+1,ned,ust,ued,num);
//	cout<<"!!!"<<endl;
	pushup(root);
}
ll query(int root,int nst,int ned,int qst,int qed)//区间查询
{//n:当前区间,q:查询区间
//	cout<<"HAHAHA"<<endl;
	if(qst>ned||qed<nst)//没有交集
		return 0;
	if(qst<=nst&&qed>=ned)//覆盖该区间,返回此区间值
		return segTree[root].val;
	pushdown(root,nst,ned);
	int mid=(nst+ned)>>1;
	return query(root*2,nst,mid,qst,qed)+query(root*2+1,mid+1,ned,qst,qed);
//	cout<<"???"<<endl;
}
ll a[maxn];
int main()
{
	int n,m,x,y;
	ll k;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,a,1,n);
	while(m--)
	{
		int flag;
		scanf("%d",&flag);
		if(flag==1)
		{
			scanf("%d%d%lld",&x,&y,&k);
			update(1,1,n,x,y,k);
		}
		else
		{
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,1,n,x,y));
		}
	}
	return 0;
}
