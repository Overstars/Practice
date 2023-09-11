#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int x[maxn],y[maxn],c[maxn];
int a[maxn],t[maxn<<1];
int discretization(int n)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		t[++cnt]=x[i];
		t[++cnt]=y[i];
	}
	sort(t+1,t+cnt+1);
	int m=unique(t+1,t+cnt+1)-t-1;//m为离散化后范围
// 	for(int i=1;i<=n;i++)
//		a[i]=lower_bound(t+1,t+m+1,a[i])-t;//a[i]即为离散化后的a[i]相对大小
	return m;
}
int fin(int x,int lim)
{
	return lower_bound(t+1,t+lim+1,x)-t;
}
#define lowbit(x) (x&(-x))
void update(int k,int num,int n)
{
	while(k<=n)
	{
		c[k]+=num;
		k+=lowbit(k);
	}
}
int query(int k)
{
	int sum=0;
	while(k)
	{
		sum+=c[k];
		k-lowbit(k);
	}
	return sum;
}
int main()
{
	int k;
	cin>>k;
	for(int i=1;i<=k;i++)
		cin>>x[i]>>y[i];
	int lim=discretization(k);
	printf("lim=%d\n",lim);
	for(int i=1;i<=lim;i++)
		a[i]=i;
	for(int i=1;i<=k;i++)
	{
		int l=fin(x[i],lim),r=fin(y[i],lim);
		swap(a[l],a[r]);
	}
	for(int i=1;i<=lim;i++)
		printf("%d ",a[i]);
	int ans=0;
	for(int i=lim;i;i--)
	{
		ans+=query(a[i]-1);
		update(a[i],1,lim);
	}
	cout<<ans<<endl;
	return 0;
}
