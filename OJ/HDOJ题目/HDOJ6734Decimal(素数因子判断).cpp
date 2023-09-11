#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//�������,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
const int MAXN=105;
int prime[MAXN+1],primesize;//primesize�������ĸ���,prime[i]���ŵ�i������
bool isprime[MAXN+1];
void getlist(void)
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
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int t,n;
	getlist();
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool flag=0;
		for(int i=1;i<100&&!flag;i++)
		{
			if(prime[i]>n)
				break;
			if(prime[i]==2||prime[i]==5)//ֻ��2��5����������
				continue;//��1/n��Ϊ����С��
			else if(n%prime[i]==0)
			{
				flag=1;
			}
		}
		cout<<(flag?"Yes":"No")<<endl;
	}
	return 0;
}
