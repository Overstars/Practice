#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
long long dis[500005];
bool jud(long long x,int len,int val)
{
	int cnt=0,pre=0,i;//记录中间应去掉(距离小于mid)的石头
//	printf("mid=%lld\n",x);
	for(i=1;i<=len;i++)
	{
		if(dis[i]-dis[pre]<x)
			cnt++;
		else
			pre=i;
//		printf("i=%d,pre=%d,cnt=%d\n",i,pre,cnt);
	}
	if(cnt>val)
		return 0;
	else
		return 1;
}
int main()
{
	long long l,temp,maxn=inf;
	int n,m;
	cin>>l>>n>>m;//距离,中间岩石数,最多移走的岩石数
	int i,j;//输出可能的最长的最短跳跃距离
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&dis[i]);
//		dis[i]=dis[i-1]+temp;
		maxn=min(maxn,dis[i]-dis[i-1]);
	}
	maxn=min(maxn,l-dis[n]);
	dis[n+1]=l;
	long long left=maxn,right=l,mid,ans;
	while(left<=right)
	{
		mid=(left+right)>>1;
		if(jud(mid,n,m)){
			ans=mid;
			left=mid+1;//尝试更优解
		}
		else
			right=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
