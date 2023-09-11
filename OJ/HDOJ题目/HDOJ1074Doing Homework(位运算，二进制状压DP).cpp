#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f,maxn=16;
struct task
{
	char name[105];
	int date,req;//��ֹ����,ʵ������
} a[maxn];
struct
{
	int now,cost,pre;//��ǰ�۷�״̬,����ǰ״̬����ʱ��,��һ��״̬
} dp[1<<maxn];//������״ѹDP,��λ����λ�����i�ſ��Ƿ����
void show(int x)//���ݽ�״̬,��ӡ�������״̬���Ŀγ�
{
	if(x==0)
		return;
	show(x-(1<<dp[x].pre));
	printf("%s\n",a[dp[x].pre].name);
}
int main()
{
	int t,n,i,j;//����˳��,����۷����ٵķ���
	cin>>t;
	while(t--)
	{
		cin>>n;
		int tot=1<<n;
		for(i=0;i<n;i++)
			scanf("%s %d%d",a[i].name,&a[i].date,&a[i].req);
		memset(dp,0,sizeof(dp));
		for(i=1;i<tot;i++)//�ö����ƿ���i,�����п��ܱ���
		{//�����j��Ŵ�0��ʼ
			dp[i].now=inf;//��ʼ���۷�Ϊinf
			for(j=n-1;j>=0;j--)//���ҵ�j+1��(��ż�j),��ΪҪ���ֵ���,���ԴӺ���ǰ
			{
				int temp=1<<j;//
				if(!(i&temp))//��״̬iʱ��j��û����
					continue;//����iһ����temp,i-temp��ʾiû������j�ŵ�״̬
				int score=dp[i-temp].cost+a[j].req-a[j].date;//�������j�ŵ���i�Ŀ۷�,�ﵽi-temp�����ܹ�ʵ��ʱ��+����-�涨
				//���ｲ����,��Ϊ��������ʱ��*ͬʱ����*,��������j����������ʱ��Ҫ����i-temp�����ܹ�ʵ��ʱ��
				if(score<0)//�۷�һ����Ϊ��(���г���û����Ŀζ���۷�)
					score=0;
				if(dp[i].now>dp[i-temp].now+score)//����ǰ�۷ִ��ڣ�i-temp״̬�Ŀ۷�+��i-temp��i�Ķ���۷֣�
				{
					dp[i].now=dp[i-temp].now+score;//�������״̬�۵��ķ���(����ʱ��)
					dp[i].cost=dp[i-temp].cost+a[j].req;//�������״̬�ܹ�ʵ�ʻ���ʱ��
					dp[i].pre=j;//��¼�������״̬���Ŀγ�
				}
			}
		}
		printf("%d\n",dp[tot-1].now);//ȫ�����ζ�����Ŀ۷�״̬
		show(tot-1);
	}
	return 0;
}
