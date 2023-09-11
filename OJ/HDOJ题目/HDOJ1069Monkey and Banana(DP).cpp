#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
struct box
{
	int x,y,z;
} a[205];
int dp[205];//长\宽\高,可以翻转
bool cmp(box a,box b)//之前没看到无限供应楞了半天
{
//	return a.x>b.x&&a.y>b.y||a.x>b.y&&a.y>b.x;
	if(a.x==a.x)
		return a.y>b.y;//宽相同按长排序
	return a.x>b.x;//按边长排序,宽大的排在前
}
int main()
{
	int n,i,j,t=0;//将n个木块摞起来,上方木块长宽严格小于下方
	while(cin>>n&&n){//求最高能达到的高度
		int cnt=0;
		for(i=0;i<n;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			a[cnt].x=x,a[cnt].y=y,a[cnt].z=z;
			cnt++;
			a[cnt].x=x,a[cnt].y=z,a[cnt].z=y;//判断时候要转一转
			cnt++;
			a[cnt].x=z,a[cnt].y=y,a[cnt].z=x;
			cnt++;
			a[cnt].x=z,a[cnt].y=x,a[cnt].z=y;
			cnt++;
			a[cnt].x=y,a[cnt].y=x,a[cnt].z=z;
			cnt++;
			a[cnt].x=y,a[cnt].y=z,a[cnt].z=x;
			cnt++;
		}
		sort(a,a+cnt,cmp);
		for(i=0;i<cnt;i++){
			dp[i]=a[i].z;//以i结尾的最大高度,高度至少为自身
			for(j=i-1;j>=0;j--){//从该层向下遍历,挨个尝试
				if((a[j].x>a[i].x&&a[j].y>a[i].y)||(a[j].y>a[i].x&&a[j].x>a[i].y))
					dp[i]=max(dp[i],a[i].z+dp[j]);//塞在下面
			}
		}
		int maxn=0;
		for(i=0;i<cnt;i++)
			maxn=max(maxn,dp[i]);
		printf("Case %d: maximum height = %d\n",++t,maxn);
	}
	return 0;
}
