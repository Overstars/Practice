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
				if(arr[j]<arr[i])//j�������iС,dp[j]Ϊj֮ǰ��ȡ�������ֵ,����ÿ�С��arr[j]
					dp[i]=max(dp[i],dp[j]);
			if(dp[i]>-INF)
				dp[i]+=arr[i];
			else
				dp[i]=arr[i];//��������Ͷ���...���,��Ȼ��-INF˵��arr[i]����С������,Ӧ�ò�Ӱ������
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
