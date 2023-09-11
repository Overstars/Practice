#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f,maxn=16;
struct task
{
	char name[105];
	int date,req;//截止日期,实际所需
} a[maxn];
struct
{
	int now,cost,pre;//当前扣分状态,到当前状态花费时间,上一个状态
} dp[1<<maxn];//二进制状压DP,低位到高位代表第i门课是否完成
void show(int x)//传递进状态,打印来到这个状态做的课程
{
	if(x==0)
		return;
	show(x-(1<<dp[x].pre));
	printf("%s\n",a[dp[x].pre].name);
}
int main()
{
	int t,n,i,j;//安排顺序,输出扣分最少的方案
	cin>>t;
	while(t--)
	{
		cin>>n;
		int tot=1<<n;
		for(i=0;i<n;i++)
			scanf("%s %d%d",a[i].name,&a[i].date,&a[i].req);
		memset(dp,0,sizeof(dp));
		for(i=1;i<tot;i++)//用二进制看待i,将所有可能遍历
		{//这里的j编号从0开始
			dp[i].now=inf;//初始化扣分为inf
			for(j=n-1;j>=0;j--)//查找第j+1门(编号即j),因为要求字典序,所以从后往前
			{
				int temp=1<<j;//
				if(!(i&temp))//若状态i时第j门没有做
					continue;//否则i一定≥temp,i-temp表示i没有做第j门的状态
				int score=dp[i-temp].cost+a[j].req-a[j].date;//最后做第j门到达i的扣分,达到i-temp所用总共实际时间+所需-规定
				//这里讲解下,因为所有任务时间*同时减少*,所以做第j项任务所用时间要加上i-temp所用总共实际时间
				if(score<0)//扣分一定不为负(所有超期没做完的课都会扣分)
					score=0;
				if(dp[i].now>dp[i-temp].now+score)//若当前扣分大于（i-temp状态的扣分+由i-temp到i的额外扣分）
				{
					dp[i].now=dp[i-temp].now+score;//更新这个状态扣掉的分数(超额时间)
					dp[i].cost=dp[i-temp].cost+a[j].req;//更新这个状态总共实际花费时间
					dp[i].pre=j;//记录来到这个状态做的课程
				}
			}
		}
		printf("%d\n",dp[tot-1].now);//全部功课都做完的扣分状态
		show(tot-1);
	}
	return 0;
}
