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
int a[2005],b[2005],dp[2005];
int main()
{
	int n,k;//有k个人
	cin>>n;
	while(n--){
		cin>>k;
		for(int i=1;i<=k;i++)
			scanf("%d",&a[i]);//单独买票时间
		for(int i=2;i<=k;i++)
			scanf("%d",&b[i]);//和前面的人买票花费时间
		memset(dp,inf,sizeof(dp));
		dp[0]=0;
		dp[1]=a[1];
		for(int i=2;i<=k;i++)
			dp[i]=min(dp[i-1]+a[i],dp[i-2]+b[i]);//前i个人买完票用的最短时间
		int time=dp[k]%(24*60*60);//单位秒
		bool ismoring=1;
		int hour=time/3600,minute=(time%3600)/60,second=time%60;//
		if(8+hour==12){
			ismoring=0;
			hour+=8;
		}
		else if(8+hour>12){
			ismoring=0;
			hour=(8+hour)%12;
		}
		else{
			hour+=8;
		}
//		printf("ans=%d\n",dp[k]);
		printf("%02d:%02d:%02d %s\n",hour,minute,second,ismoring?"am":"pm");
	}
	return 0;
}
