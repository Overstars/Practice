#include<bits/stdc++.h>
using namespace std;
const int maxn=10005,inf=0x3f3f3f3f;
int a[maxn],sg[maxn];
bool vis[maxn];
void getsg(int arr[],int n)//arr存储可以走的步数
{
	sort(arr+1,arr+n+1);
	memset(sg,0,sizeof(sg));
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=arr[0];j++)
		{
			if(i<arr[j])
				break;
			vis[sg[i-arr[i]]]=1;
		}
		for(int j=0;j<=n;j++)
			if(!vis[j])
			{
				sg[i]=j;
				break;
			}
	}
}
int main()
{
	int t,n;
	cin>>t;
	a[0]=inf;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{//该题sg[a[i]]]即为a[i]
			cin>>a[i];
		}
//		getsg(a,n);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
//			printf("sg[%d]=%d\n",i,sg[i]);
			ans^=a[i];
		}
		if(ans)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
