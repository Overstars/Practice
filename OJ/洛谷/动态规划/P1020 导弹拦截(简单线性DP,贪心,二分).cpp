#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
int read()//快读挂
{
    int x=0,f=1;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return x*f;
}
//#define DEBUG
int a[100005],dp[100005],hei[100005];
int h1[100005];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("P1020.in", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int cnt=0,maxn=0;
	while(cin>>a[cnt++]);
//		dp[cnt++]=1;
//	for(int i=1;i<cnt;i++)
//	{//拦截第i个时的最大数量
//		for(int j=0;j<i;j++)
//		{
//			if(a[j]>=a[i]&&dp[j]+1>dp[i])
//				dp[i]=dp[j]+1;
//		}
//		maxn=max(maxn,dp[i]);
//	}
//	cout<<maxn<<endl;
	int len=0;
	h1[0]=a[0];//len为拦截最大数量
	for(int i=1;i<cnt;i++)//求最长不上升子序列
	{
		if(h1[len]>=a[i])//系统的高度比导弹高
			h1[++len]=a[i];//可以拦下
		else//在下降序列里找第一个小于a[i]的数,并且用a[i]替换
			*upper_bound(h1,h1+1+len,a[i],greater<int>())=a[i];
//		int k=upper_bound(h1+1,h1+1+len,a[i],greater<int>())-h1;
//		h1[i]=a[i];
//		dp[i]=k;
//		len=max(len,dp[i]);
	}
	cout<<len<<endl;
	int ans=1;
	hei[1]=a[0];
	for(int i=1;i<cnt;i++)//拦截i号导弹
	{
		if(hei[ans]<a[i])//hei数组有序
		{
			hei[++ans]=a[i];
		}
		else{
			*lower_bound(hei+1,hei+ans+1,a[i])=a[i];//找到第一个不小于a[i]的数
		}
	}
	cout<<ans<<endl;
	return 0;
}
