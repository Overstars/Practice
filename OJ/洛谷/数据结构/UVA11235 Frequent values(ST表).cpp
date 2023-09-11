#include<bits/stdc++.h>
using namespace std;
const int maxn=10005,inf=0x3f3f3f3f;
int a[maxn],d[maxn][30],lg[maxn]={-1};
void init(int n)
{
	for(int j=1;(1<<j)<=n;j++)//枚举长度
	{
		for(int i=1;(i+j)<=n;i++)//枚举起点
		{

		}
	}
}
int main()
{
	int n,q;
	while(cin>>n>>q)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
//			lg[i]=lg[i-1]+((i<<(lg[i-1]+1))==i);
			lg[i]=lg[i>>1]+1;
		}
		while(q--)
		{
			int l,r;
			cin>>l>>r;
		}
	}
	return 0;
}
