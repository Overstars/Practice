#include<iostream>
using namespace std;
int p[105];//各个充电站离跑道起点的距离
double dp[105];//各个充电站离跑道起点的时间
long long c[105];//电动车到第i个剩余行驶距离
const int INF=0x3f3f3f;
double mini(double a,double b)
{
	return (a<b)?a:b;
}
int main()
{
	long long l,n,c,t;
	while(cin>>l){//跑道的总长度
		long long vr,vt1,vt2,i,j;
		cin>>n>>c>>t;//充电站个数,满电行驶距离,充电所需时间
		cin>>vr>>vt1>>vt2;//兔子速度,电动车速度,脚蹬速度
		p[0]=0;
		for(i=1;i<=n;i++)
			cin>>p[i];//充电站离跑道起点的距离
		p[n+1]=l;//到终点的距离
		dp[0]=0;//起点到起点的时间

		for(i=1;i<=n+1;i++){
			dp[i]=(double)(p[i]-p[0])/vt2;//从起点到i的时间,初始化为脚蹬时间
			for(j=0;j<i;j++){//在第j个节点充电,开到i
				double time;//t1是在j充电再到i所用时间
				if(c>=p[i]-p[j])//不写出[在j不充电开到i]是因为内层循环在之前(小于j时)实现了这种情况
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
