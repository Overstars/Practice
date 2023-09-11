#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int ques[maxn][5];//第i个问题被j知道
bool vis[1<<6];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)//n个问题
	{
		int now=0,tmp;
		for(int j=0;j<k;j++)//k组状态,一共2^k种
		{
			cin>>tmp;
			now+=(1<<j)*tmp;//状压
		}
		if(now==0)//所有队伍都不知道
		{
			cout<<"YES\n";
			exit(0);
		}
		vis[now]=1;
	}
	for(int i=0;i<=(1<<k);i++)//第一个问题的状态
	{
		for(int j=i+1;j<=(1<<k);j++)
		{
			if(!vis[i]||!vis[j])
				continue;
//			printf("%d,%d\n",i,j);
			if((i&j)==0)
			{
				cout<<"YES\n";
				exit(0);
			}
		}
	}
	cout<<"NO\n";
	return 0;
}
/*
 *从n个问题里选出一些问题
 *要求每个队伍不能知道超过一半问题的答案
 *求是否存在这样的问题集
 */
