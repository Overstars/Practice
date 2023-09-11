#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f,maxn=1005;
char str[maxn];
int sum[maxn];
void change(int l,int r)
{
	int i=l,j=r;
	while(i<j)
	{
		swap(str[i],str[j]);
		i++;
		j--;
	}
	for(;l<=r;l++)
		sum[l]=sum[l-1]+(str[l]=='('?1:-1);
}
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		queue<pair<int,int> > ans;
		scanf("%d%d%s",&n,&k,str+1);
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='(')
				sum[i]=sum[i-1]+1;
			else
				sum[i]=sum[i-1]-1;
		}
		int pre=0,cnt=0;
		bool flag=0;
		for(int i=1;i<=n;i++)//检测非法
		{
			if(sum[i]<0&&!flag)
				pre=i,flag=1;
			if(sum[i]==0&&flag)
			{
				change(pre,i);
				flag=0;
				ans.push(make_pair(pre,i));
				cnt++;
			}
		}
//		printf("调整后:%s\n",str+1);
		int zero=0;
		for(int i=1;i<=n;i++)
			if(sum[i]==0)
				zero++;
		while(zero>k)//合并
		{
			for(int i=1;i<n;i++)
			{
				if(sum[i]<sum[i-1]&&str[i]==')'&&str[i+1]=='(')
				{
					change(i,i+1);
					ans.push(make_pair(i,i+1));
//					printf("[%d,%d]:%s\n",i,i+1,str+1);
					cnt++;
					zero--;
					break;
				}
			}
		}
		while(zero<k)//拆分
		{
			for(int i=1;i<n;i++)
			{
				if(sum[i]>sum[i+1]&&sum[i+1]>0&&str[i]=='('&&str[i+1]==')')
				{
					change(i,i+1);
					ans.push(make_pair(i,i+1));
					cnt++;
					zero++;
					break;
				}
			}
		}
		cout<<cnt<<'\n';
		while(!ans.empty())
		{
			cout<<ans.front().first<<' '<<ans.front().second<<'\n';
			ans.pop();
		}
	}
	return 0;
}

