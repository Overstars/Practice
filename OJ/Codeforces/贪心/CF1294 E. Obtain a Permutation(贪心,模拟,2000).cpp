#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,inf=0x3f3f3f3f;
vector<int> a[maxn];
int cnt[maxn];
int main()
{
	int n,m,tmp,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i].push_back(0);
		for(int j=1;j<=m;j++)
		{
			cin>>tmp;
			a[i].push_back(tmp);
		}
	}
	for(int i=1;i<=m;i++)//每一列单独计算
	{
		int now=inf;
		for(int j=0;j<=n;j++)
			cnt[j]=0;//向上移动i位符合的元素
		for(int j=1;j<=n;j++)//第j行元素向上移动x行到合适位置
		{
			if(a[j][i]<1||a[j][i]>n*m||(a[j][i]-i)%m!=0)//不符合这一列的元素
				continue;
			int sup=(a[j][i]-i)/m+1;//应该在的行数
			cnt[(j-sup+n)%n]++;
		}
		for(int j=0;j<n;j++)
			now=min(now,j+n-cnt[j]);
		ans+=now;
	}
	cout<<ans<<endl;
	return 0;
}
