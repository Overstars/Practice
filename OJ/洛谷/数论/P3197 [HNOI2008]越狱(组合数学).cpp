#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=100003,maxn=1e18;
int qpow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
//int dp[maxn];//dp[i][j]表示i种宗教j个房间的可能情况
signed main()
{//dp[i]表示前i号房不发生越狱的种类数
//	freopen("P3197_6.in","r",stdin);
	int n,m;//n个房间,m个宗教
	cin>>m>>n;
	int ret=m;
	ret=ret*qpow(m-1,n-1)%mod;
//	cout<<"ret="<<ret<<endl;
	cout<<(qpow(m,n)-ret+mod)%mod<<endl;
	return 0;
}
