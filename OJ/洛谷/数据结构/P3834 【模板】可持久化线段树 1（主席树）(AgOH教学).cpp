#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
vector<int> v;
inline int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
struct node
{//左右子树节点编号,区间上数量为sum
	int l,r,sum;
} hjt[maxn<<5];
int cnt,root[maxn];//内存值计数器,root[i]为根节点编号(在之前基础上插入a[i]的树)
void Insert(int l,int r,int pre,int &now,int p)//p为新加入权值(也为位置)
{//对离散化后范围[l,r]建树,pre:上一个版本的编号,now:当前版本的编号
	//找到新加入权值对应节点,更新该节点信息
	hjt[++cnt]=hjt[pre];//动态开点:上一个版本对应位置节点复制一份,新树中添加lgn个节点
	now=cnt;//当前节点编号等于新分配
	hjt[now].sum++;//插入,数量++,维护离散化后值域[l,r]上的个数
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(p<=mid)//插入到左子树
		Insert(l,mid,hjt[pre].l,hjt[now].l,p);
	else//插入到右子树上
		Insert(mid+1,r,hjt[pre].r,hjt[now].r,p);
}
int query(int l,int r,int L,int R,int k)
{//[l,r]:离散化后查询范围,L/R:树的版本编号
	if(l==r)//叶子节点
		return l;
	int mid=(l+r)>>1;
	/*
	 前缀和思想,求出[1,r]的数量
	 用r版本减去l-1版本的同一区间信息,得到指定查询区域[l,r]的线段树
	 */
	//新减出来的差值树上,左子树数值
	int tmp=hjt[hjt[R].l].sum-hjt[hjt[L].l].sum;//
	if(k<=tmp)//第k大在左子树上
		query(l,mid,hjt[L].l,hjt[R].l,k);
	else
		query(mid+1,r,hjt[L].r,hjt[R].r,k-tmp);
}
int main()//区间第k大
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());//对v去重
	for(int i=1;i<=n;i++)//维护离散化后的值域上个数
	{//思想:保存插入时的历史版本,对每个前缀建树(n棵)
		Insert(1,v.size(),root[i-1],root[i],getid(a[i]));
	}//第i棵存储前i个值出现次数
	while(m--)
	{
		int l,r,k;
		cin>>l>>r>>k;//[l,r]不是数值范围,是数列上给定区间,即a[l:r]上第k大
		cout<<v[query(1,n,root[l-1],root[r],k)-1]<<endl;
	}
	return 0;
}
