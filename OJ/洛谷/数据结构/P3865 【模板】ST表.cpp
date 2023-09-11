#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;
int a[maxn],d[maxn][20],lg[maxn];
void init(int n)
{//d[i][j]表示以i为起点,2^j长度的最值
	for(int i=1;i<=n;i++)
		d[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++)//枚举长度
		for(int i=1;i+(1<<j)-1<=n;i++)//枚举起点,倍增+DP
			d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int rmq(int l,int r)
{
	int k=lg[r-l+1];
	return max(d[l][k],d[r-(1<<k)+1][k]);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;//长度与询问个数
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
	}
	init(n);
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",rmq(l,r));
	}
	return 0;
}
