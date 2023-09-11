#include<cstdio>
using namespace std;
const int mod=1000003;
long long ans[1000005]={0,1,2};
int main()
{
	int i,n;
	for(i=3;i<mod;i++)
		ans[i]=ans[i-1]*i%mod;
	while(scanf("%d",&n)==1)
		printf("%lld\n",n>=mod?0:ans[n]);
	return 0;
}
