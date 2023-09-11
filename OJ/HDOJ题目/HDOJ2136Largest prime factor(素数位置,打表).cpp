#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000001
using namespace std;
int ans[maxn];
int main()
{
	memset(ans,-1,sizeof(ans));
	ans[1]=0;
	int i,j,cnt=0;
	for(i=2;i<maxn;i++)//说明i为素数
		if(ans[i]==-1){
			cnt++;//素数个数
			for(j=i;j<maxn;j+=i)//i的所有倍数
				ans[j]=cnt;
		}
	while(scanf("%d",&i)==1)
		printf("%d\n",ans[i]);
	return 0;
}
