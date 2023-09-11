#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int a[100004];
bool vis[100005];
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		cin>>n;
		bool flag=1;
		int rec=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]<i||a[i]<rec)//检查是否合法
				flag=0;
			rec=max(rec,a[i]);
		}
		if(!flag)
		{
			cout<<-1<<'\n';
			continue;
		}
		queue<int>ans;
		vis[a[1]]=1;
		ans.push(a[1]);
		int maxm=a[1];
		for(int i=2;i<=n;i++)
		{
			if(a[i]>maxm)
			{
				ans.push(a[i]);
				maxm=a[i];
			}
			else
			{//只会等于
				int i;
				for(i=1;i<maxm;i++)
				{
					if(!vis[i])
					{
						ans.push(i);
						vis[i]=1;
						break;
					}
				}
				if(i==maxm)
					flag=0;
			}
			if(!flag)
				break;
		}
		if(!flag)
		{
			cout<<-1<<'\n';
			continue;
		}
		while(!ans.empty())
		{
			cout<<ans.front()<<' ';
			ans.pop();
		}
		cout<<'\n';
	}
	return 0;
}
