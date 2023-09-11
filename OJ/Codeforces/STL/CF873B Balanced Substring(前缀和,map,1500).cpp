#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int sum[maxn];
int main()
{
	int n,ans=0;;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1')
			sum[i]=sum[i-1]+1;
		else
			sum[i]=sum[i-1]-1;
//		printf("sum[%d]=%d\n",i,sum[i]);
	}
	map<int,int> mp;//数量,到位置
	mp[0]=0;//特殊注意
	for(int i=1;i<=n;i++)
	{
		if(mp.count(sum[i])==0)//先加入的更优
		{
			mp[sum[i]]=i;
		}
		else
		{
			ans=max(ans,i-mp[sum[i]]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
