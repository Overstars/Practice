#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[10005];//���,����,����
double b[10005],dp[10005];//���뵽����,iԪ���뵽����߸���
int main()
{
	int i,j;
	while(scanf("%d %d",&n,&m)==2&&(n||m)){
		for(i=0;i<m;i++){
			scanf("%d %lf",&a[i],&b[i]);
		}
		memset(dp,0,sizeof(dp));
		for(i=0;i<m;i++){//m��ѧУ�еĵ�i��
			for(j=n;j>=a[i];j--)//jΪӵ�н��,Ҫ�ӽ���С����,���������i��ѧУ�ظ�ѡ���Ч��
				dp[j]=max(dp[j],1-(1-dp[j-a[i]])*(1-b[i]));//���Ϊj-a[i]������
		}
		printf("%.1lf%%\n",dp[n]*100);
	}
	return 0;
}
