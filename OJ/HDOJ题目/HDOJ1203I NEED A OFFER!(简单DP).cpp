#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[10005];//金额,数量,费用
double b[10005],dp[10005];//申请到概率,i元申请到的最高概率
int main()
{
	int i,j;
	while(scanf("%d %d",&n,&m)==2&&(n||m)){
		for(i=0;i<m;i++){
			scanf("%d %lf",&a[i],&b[i]);
		}
		memset(dp,0,sizeof(dp));
		for(i=0;i<m;i++){//m个学校中的第i个
			for(j=n;j>=a[i];j--)//j为拥有金额,要从金额大到小计算,否则产生第i所学校重复选择的效果
				dp[j]=max(dp[j],1-(1-dp[j-a[i]])*(1-b[i]));//金额为j-a[i]最大概率
		}
		printf("%.1lf%%\n",dp[n]*100);
	}
	return 0;
}
