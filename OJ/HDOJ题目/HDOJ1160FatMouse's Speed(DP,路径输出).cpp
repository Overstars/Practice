#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
struct node
{
	int no,w,s;
} a[10005];
bool cmp(node x,node y)
{
	return x.w<y.w;//从小到大排序
}
int dp[10005],pre[10005];
void show(int x)
{
	if(x<0)
		return;
	show(pre[x]);
	printf("%d\n",a[x].no+1);//从0计数,要+1
//	printf("%d\n",x);//排序后顺序
}
int main()
{
	int i,j,cnt=0;
	while(cin>>a[cnt].w>>a[cnt].s)
	{
		pre[cnt]=-1;
		a[cnt].no=cnt;
		cnt++;
	}
	sort(a,a+cnt,cmp);
//	{
//		for(i=0;i<cnt;i++)
//		{
//			printf("%d:no=%d,w=%d,s=%d\n",i,a[i].no,a[i].w,a[i].s);
//		}
//	}
	int maxn=0,loc=-1;//定位最长序列末尾
	dp[0]=1;
	for(i=1;i<cnt;i++)//判断i是否可以接上
	{//dp[i]表示以i结尾的最长序列长度
		dp[i]=1;//加了这个就AC了...
		for(j=0;j<i;j++)
		{
			if(a[i].s<a[j].s&&a[i].w>a[j].w)//符合条件
				if(dp[i]<(dp[j]+1))//i接在j后面
				{
					dp[i]=dp[j]+1;
					pre[i]=j;
				}
		}
		if(maxn<dp[i])
		{
			maxn=dp[i];
			loc=i;
		}
	}
	printf("%d\n",dp[loc]);
	show(loc);
	return 0;
}
