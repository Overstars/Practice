//这题蛮奇怪的，题干说的不清楚
//如果n<=6，桌上只有有颜色的球，桌上剩1个球，菲利普得分是7，剩两个，得分是6+7=13。以此类推，菲利普最终得分是p+剩余颜色球的得分。
//如果n>6，桌上有红球和有颜色球，那么菲利普最终得分是a+1*（n-6）表示剩余红球得分+7*（n-6）表示菲利普每次击中红球后都选择击中黑球来得分+27表示把所有颜色球得分获得。
#include<stdio.h>
#include<stdlib.h>
int main(void)
{

	long long n,ball,p,o;
	scanf("%lld",&n);
	while(n--){
		scanf("%lld %lld %lld",&ball,&p,&o);
		long long end=p;
		if(ball<=6)//只剩彩球
		{
			int temp=7;
			while(ball--)
				end+=(temp--);//之前这人用什么策略打球题目都没说……
		}
		else
			end=p+(ball-6)*8+27;
		if(end>=o)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
