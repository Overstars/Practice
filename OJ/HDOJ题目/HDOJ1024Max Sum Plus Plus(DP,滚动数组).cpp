#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int a[1000005],dp[2][1000005];//dp[i][j]��ʾ�ڵ�j��Ԫ��ѡ��ǰi�ε�����(so,jΪi�εĽ�βԪ��)
int main()
{
	int m,n,i,j,flag=0;
	while(cin>>m>>n){//��n�������ҳ����غϵ�m��,ʹ�ܺ����
		flag=0;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=m;i++){
			dp[flag][i]=dp[1-flag][i-1]+a[i];//�������ǰ���AC�ˣ����б�-inf��С��������ֹ��ʼ��Ϊ0�ĸ��ţ�
			int maxpre=dp[1-flag][i-1];
//			int maxpre=INT_MIN;
			for(j=i+1;j<=n;j++){//i-1�������õ�i-1��Ԫ��
				maxpre=max(maxpre,dp[1-flag][j-1]);
				dp[flag][j]=max(dp[flag][j-1]+a[j],maxpre+a[j]);
			}//����a[j]���뵽��i����,����a[j]������Ϊ��i��
			flag=1-flag;
		}
		int maxn=dp[1-flag][m];
		for(i=m+1;i<=n;i++)
			maxn=max(maxn,dp[1-flag][i]);
		cout<<maxn<<endl;
	}
	return 0;
}
