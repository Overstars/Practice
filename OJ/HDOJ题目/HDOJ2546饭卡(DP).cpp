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
		int able=m-5;//�����Ķ���ǰ���õ�Ǯ(��������)
		memset(dp,0,sizeof(dp));
		if(able>a[0]){
			for(int i=0;i<n-1;i++)//n-1����,��i������
				for(int j=able;j>=a[i];j--)//��ǰ��jԪ,���ڲ˼�ʱ������
					dp[j]=max(dp[j],dp[j-a[i]]+a[i]);//�Ӵ�С����,��ֹ�ظ�����
		}
		cout<<m-dp[able]-a[n-1]<<endl;
	}
	return 0;
}
