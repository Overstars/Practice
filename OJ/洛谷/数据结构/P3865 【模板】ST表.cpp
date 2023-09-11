#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;
int a[maxn],d[maxn][20],lg[maxn];
void init(int n)
{//d[i][j]��ʾ��iΪ���,2^j���ȵ���ֵ
	for(int i=1;i<=n;i++)
		d[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++)//ö�ٳ���
		for(int i=1;i+(1<<j)-1<=n;i++)//ö�����,����+DP
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
	int n,m;//������ѯ�ʸ���
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
