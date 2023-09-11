#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int main()
{
	int n,a[1005],m,dp[1005];
	while(cin>>n&&n){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		if(m<5){
			cout<<m<<endl;
			continue;
		}
		sort(a,a+n);
		int able=m-5;//买最贵的东西前可用的钱(背包容量)
		memset(dp,0,sizeof(dp));
		if(able>a[0]){
			for(int i=0;i<n-1;i++)//n-1道菜,第i道买不买
				for(int j=able;j>=a[i];j--)//当前有j元,大于菜价时才能买
					dp[j]=max(dp[j],dp[j-a[i]]+a[i]);//从大到小更新,防止重复购买
		}
		cout<<m-dp[able]-a[n-1]<<endl;
	}
	return 0;
}
