#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f;
int arr[1005],dp[1005];
int main()
{
	int n,i,j;
	while(cin>>n&&n){
		for(i=0;i<n;i++)
			cin>>arr[i];
		dp[0]=arr[0];
		for(i=1;i<n;i++){
			dp[i]=-INF;
			for(j=0;j<i;j++)
				if(arr[j]<arr[i])//j所在项比i小,dp[j]为j之前能取到的最大值,其中每项都小于arr[j]
					dp[i]=max(dp[i],dp[j]);
			if(dp[i]>-INF)
				dp[i]+=arr[i];
			else
				dp[i]=arr[i];//加上这个就对了...奇怪,既然是-INF说明arr[i]是最小的那项,应该不影响结果的
		}
		int ans=-INF;
		for(i=0;i<n;i++)
			if(dp[i]>ans)
				ans=dp[i];
//		cout<<max(ans,0)<<endl;
		printf("%d\n",ans);
	}
	return 0;
}
