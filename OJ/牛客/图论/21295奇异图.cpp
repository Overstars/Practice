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
typedef long long ll;
const int inf=0x3f3f3f3f;
//#define DEBUG
int a[105];
bool to[105][105],v[105];
ll dfs(int x,int n)
{
	ll ret=1;
	v[x]=1;//搜索x可到达点的数量
	for(int i=1;i<=n;i++)
		if(!v[i]&&to[x][i])
			ret+=dfs(i,n);
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);//按出度排序
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			to[j][i]=1;//标准完全图
	for(int i=1;i<=n;i++)
		a[i]-=i-1;//实际的出度-标准的出度
	for(int i=1;i<=n;i++)
	{
		bool vis[105]={0};
		while(a[i]<0)//若a[i]<0,说明标准出度多了,要在标准图中减少i点出度
		{
			int id=-1;
			for(int j=1;j<i;j++)//i与前面的j点的边反过来,即id->i
				if(a[j]>0&&!vis[j]&&(id==-1||a[j]>a[id]))
				{//a[j]>0说明标准出度少了,要增加j的出度
					id=j;
				}
			a[id]--;
			a[i]++;
			to[id][i]=1;
			to[i][id]=0;
			vis[id]=1;
		}
	}
	#ifdef DEBUG
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)
		{
			printf("%d,",to[i][j]);
		}
		printf("\n");
	}
	printf("a数组:\n");
	for(int i=1;i<=n;i++)
		printf("%d,",a[i]);
	printf("\n********\n");
	#endif // DEBUG
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		memset(v,0,sizeof(v));
		ans+=dfs(i,n);
	}
	cout<<ans<<endl;
	return 0;
}
