#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
const int MAXN=16005;
int prime[MAXN+1],primesize;//primesize是素数的个数,prime[i]存着第i个素数
bool isprime[MAXN+1];
void getlist()
{
	memset(isprime,1,sizeof(isprime));
	primesize=0;
	isprime[1]=false;
	for(int i=2;i<=MAXN;i++)
	{
		if(isprime[i])
			prime[++primesize]=i;
		for(int j=1;j<=primesize&&i*prime[j]<=MAXN;j++)
		{
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
		}
	}
}
int main()
{
	getlist();
	int n,cnt=0;
	while(cin>>n&&n>0){
		if(n==1||n==2||!isprime[n])
			printf("%d: no\n",++cnt);
		else
			printf("%d: yes\n",++cnt);
	}
	return 0;
}
