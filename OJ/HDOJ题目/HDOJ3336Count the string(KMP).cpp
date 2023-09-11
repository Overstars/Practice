#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=10007;
char str[200005];
int nex[200005];//KMP中next[i]为t[0:i]最长公共前后子串长度
void getnex(int n)
{
	nex[0]=0;
	for(int i=1,j=0;i<n;i++)
	{
		while(j>0&&str[i]!=str[j])
			j=nex[j-1];
		if(str[i]==str[j])
			j++;
		nex[i]=j;
	}
//	for(int i=0;i<n;i++)
//	{
//		printf("下标:%d,nex[i]=%d\n",i,nex[i]);
//	}
}
int main()//求所有前缀遍历匹配次数
{
	int t,n;
	cin>>t;
	while(t--)
	{
		scanf("%d %s",&n,str);
		getnex(n);
		int ans=n;//每个都和自己匹配
		for(int i=1;i<n;i++)
		{
			int t=nex[i];
			while(t)
			{
				ans=(ans+1)%mod;//
				t=nex[t-1];//转移到下标为公共串长度-1开始匹配
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
