#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
ll a[maxn];
int n;
struct node
{
	ll val,ma;
} tree[maxn<<2];
void pushup(int root)
{
	tree[root].val=tree[root<<1].val+tree[root<<1|1].val;
	tree[root].ma=max(tree[root<<1].ma,tree[root<<1|1].ma);
}
void build(int root,int l,int r)
{
	if(l==r)
	{
		tree[root].ma=tree[root].val=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	pushup(root);
}
void modify(int root,int nst,int ned,int ust,int ued)
{
	if(nst>ued||ust>ned)
		return;
	if(ust<=nst&&ned<=ued)
	{
		if(tree[root].ma<=1)//区间最大值等于1
		{
			return;
		}
		else if(nst==ned)//区间开方
		{
			tree[root].val=tree[root].ma=(ll)sqrt(tree[root].val);
			return;
		}
	}
	int mid=(nst+ned)>>1;
	modify(root<<1,nst,mid,ust,ued);
	modify(root<<1|1,mid+1,ned,ust,ued);
	pushup(root);
}
ll query(int root,int nst,int ned,int qst,int qed)
{
	if(nst>qed||qst>ned)
		return 0;
	if(qst<=nst&&ned<=qed)
	{
		return tree[root].val;
	}
	int mid=(nst+ned)>>1;
	return query(root<<1,nst,mid,qst,qed)+query(root<<1|1,mid+1,ned,qst,qed);
}
int main()
{
	ios::sync_with_stdio(0);
	int m;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	cin>>m;
	while(m--)
	{
		int k,l,r;
		cin>>k>>l>>r;
		if(r<l)
			swap(l,r);
		if(k==0)
			modify(1,1,n,l,r);
		else
			cout<<query(1,1,n,l,r)<<'\n';
	}
	return 0;
}
