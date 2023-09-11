#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn],cnt,root[maxn];
vector<int> v;
struct node
{
	int l,r,sum;
} hjt[maxn<<6];
inline int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
void Insert(int l,int r,int pre,int &now,int p)
{
	hjt[++cnt]=hjt[pre];
	now=cnt;
	hjt[now].sum++;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(p<=mid)
		Insert(l,mid,hjt[pre].l,hjt[now].l,p);
	else
		Insert(mid+1,r,hjt[pre].r,hjt[now].r,p);
}
int query(int l,int r,int L,int R,int k)
{
	if(l==r)
		return l;
	int tmp=hjt[hjt[R].l].sum-hjt[hjt[L].l].sum;
	int mid=(l+r)>>1;
	if(k<=tmp)
		query(l,mid,hjt[L].l,hjt[R].l,k);
	else
		query(mid+1,r,hjt[L].r,hjt[R].r,k-tmp);
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++)
		Insert(1,v.size(),root[i-1],root[i],getid(a[i]));
//	cout<<"???"<<endl;
	while(m--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		cout<<v[query(1,v.size(),root[l-1],root[r],k)-1]<<endl;
	}
	return 0;
}
