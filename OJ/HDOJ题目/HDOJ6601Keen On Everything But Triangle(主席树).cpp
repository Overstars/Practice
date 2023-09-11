#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int maxn=1e5+7;
int root[maxn],cnt,a[maxn];
struct node
{
	int l,r,sum;
} hjt[maxn<<6];
vector<int> v,t;
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
	int tmp=hjt[hjt[R].r].sum-hjt[hjt[L].r].sum;
	int mid=(l+r)>>1;
	if(k<=tmp)//优先找右面树上的值
		query(mid+1,r,hjt[L].r,hjt[R].r,k);
	else
		query(l,mid,hjt[L].l,hjt[R].l,k-tmp);
}
inline bool jud(int a,int b,int c)
{
	if(a+b>c&&b+c>a&&a+c>b)
		return 1;
	return 0;
}
signed main()
{
	int n,q;
	while(~scanf("%d%d",&n,&q))
	{
		v.clear();
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			v.push_back(a[i]);
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		for(int i=1;i<=n;i++)
			Insert(1,v.size(),root[i-1],root[i],getid(a[i]));
		while(q--)
		{
			bool flag=0;
			int l,r,tot;
			long long M=0;
			scanf("%d%d",&l,&r);
			tot=r-l+1;//一共多少个数
			if(tot<3)
			{
				puts("-1");
				continue;
			}
			t.clear();
			for(int i=1;i<=3;i++)
			{//区间第i大
				t.push_back(v[query(1,v.size(),root[l-1],root[r],i)-1]);
				M+=t[i-1];
//				cout<<i<<":"<<t[i-1]<<endl;
			}
			if(jud(t[0],t[1],t[2]))
				flag=1;
			if(flag)
			{
				printf("%lld\n",M);
				continue;
			}
			for(int i=4;i<=tot;i++)
			{
				t.push_back(v[query(1,v.size(),root[l-1],root[r],i)-1]);
				M+=t[i-1]-t[i-4];
//				cout<<i<<":"<<t[i-1]<<endl;
				if(jud(t[i-3],t[i-2],t[i-1]))
				{
					flag=1;
//					cout<<t[i-3]<<","<<t[i-2]<<","<<t[i-1]<<endl;
					break;
				}
			}
			if(flag)
				printf("%lld\n",M);
			else
				puts("-1");
		}
	}
	return 0;
}
