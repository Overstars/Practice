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
const int inf=0x3f3f3f3f;
char str[505][2005];
int nex[505][2005];
bool vis[505];
void getnex(int no,int n)
{
	nex[no][0]=0;
	for(int i=1,j=0;i<n;i++)
	{
		while(j>0&&str[no][i]!=str[no][j])
			j=nex[no][j-1];
		if(str[no][i]==str[no][j])
			j++;
		nex[no][i]=j;
	}
}
bool kmp(int s,int l1,int t,int l2)//检验t是否为s的子串
{
	int cmp=0;
	for(int i=0;i<l1;i++)
	{
		while(cmp>0&&str[s][i]!=str[t][cmp])
			cmp=nex[t][cmp-1];
		if(str[s][i]==str[t][cmp])
			cmp++;
		if(cmp==l2)
			return 1;
	}
	return 0;
}
int main()
{
	int t,n,k;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str[i]);
			getnex(i,strlen(str[i]));
		}
		int flag=-1;
		for(int i=1;i<=n;i++)//将i作为答案尝试
		{
			int len1=strlen(str[i]);
			int len2;
			for(int j=1;j<i;j++)//尝试枚举短于i的串
			{

				if(vis[j]||(len2=strlen(str[j]))>len1)//
					continue;
				if(kmp(i,len1,j,len2)==0)
				{
					flag=i;
					break;
				}
				else
					vis[j]=1;
			}
		}
//		cout<<"Case #"<<k<<": "<<flag<<endl;
		printf("Case #%d: %d\n",k,flag);
	}
	return 0;
}
