#include<iostream>
using namespace std;
int p[105];//�������վ���ܵ����ľ���
double dp[105];//�������վ���ܵ�����ʱ��
long long c[105];//�綯������i��ʣ����ʻ����
const int INF=0x3f3f3f;
double mini(double a,double b)
{
	return (a<b)?a:b;
}
int main()
{
	long long l,n,c,t;
	while(cin>>l){//�ܵ����ܳ���
		long long vr,vt1,vt2,i,j;
		cin>>n>>c>>t;//���վ����,������ʻ����,�������ʱ��
		cin>>vr>>vt1>>vt2;//�����ٶ�,�綯���ٶ�,�ŵ��ٶ�
		p[0]=0;
		for(i=1;i<=n;i++)
			cin>>p[i];//���վ���ܵ����ľ���
		p[n+1]=l;//���յ�ľ���
		dp[0]=0;//��㵽����ʱ��

		for(i=1;i<=n+1;i++){
			dp[i]=(double)(p[i]-p[0])/vt2;//����㵽i��ʱ��,��ʼ��Ϊ�ŵ�ʱ��
			for(j=0;j<i;j++){//�ڵ�j���ڵ���,����i
				double time;//t1����j����ٵ�i����ʱ��
				if(c>=p[i]-p[j])//��д��[��j����翪��i]����Ϊ�ڲ�ѭ����֮ǰ(С��jʱ)ʵ�����������
					time=(double)(p[i]-p[j])/vt1;
				else
					time=(double)c/vt1+(double)(p[i]-p[j]-c)/vt2;
				if(j>0)
					time+=t;
				dp[i]=mini(dp[i],dp[j]+time);
			}
		}
		double tr=(double)l/vr;
		if(dp[n+1]<tr)
			cout<<"What a pity rabbit!"<<endl;
		else
			cout<<"Good job,rabbit!"<<endl;
	}
	return 0;
}
