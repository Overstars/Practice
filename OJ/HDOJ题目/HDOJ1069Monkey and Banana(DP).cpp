#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
struct box
{
	int x,y,z;
} a[205];
int dp[205];//��\��\��,���Է�ת
bool cmp(box a,box b)//֮ǰû�������޹�Ӧ���˰���
{
//	return a.x>b.x&&a.y>b.y||a.x>b.y&&a.y>b.x;
	if(a.x==a.x)
		return a.y>b.y;//����ͬ��������
	return a.x>b.x;//���߳�����,��������ǰ
}
int main()
{
	int n,i,j,t=0;//��n��ľ��������,�Ϸ�ľ�鳤���ϸ�С���·�
	while(cin>>n&&n){//������ܴﵽ�ĸ߶�
		int cnt=0;
		for(i=0;i<n;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			a[cnt].x=x,a[cnt].y=y,a[cnt].z=z;
			cnt++;
			a[cnt].x=x,a[cnt].y=z,a[cnt].z=y;//�ж�ʱ��Ҫתһת
			cnt++;
			a[cnt].x=z,a[cnt].y=y,a[cnt].z=x;
			cnt++;
			a[cnt].x=z,a[cnt].y=x,a[cnt].z=y;
			cnt++;
			a[cnt].x=y,a[cnt].y=x,a[cnt].z=z;
			cnt++;
			a[cnt].x=y,a[cnt].y=z,a[cnt].z=x;
			cnt++;
		}
		sort(a,a+cnt,cmp);
		for(i=0;i<cnt;i++){
			dp[i]=a[i].z;//��i��β�����߶�,�߶�����Ϊ����
			for(j=i-1;j>=0;j--){//�Ӹò����±���,��������
				if((a[j].x>a[i].x&&a[j].y>a[i].y)||(a[j].y>a[i].x&&a[j].x>a[i].y))
					dp[i]=max(dp[i],a[i].z+dp[j]);//��������
			}
		}
		int maxn=0;
		for(i=0;i<cnt;i++)
			maxn=max(maxn,dp[i]);
		printf("Case %d: maximum height = %d\n",++t,maxn);
	}
	return 0;
}
