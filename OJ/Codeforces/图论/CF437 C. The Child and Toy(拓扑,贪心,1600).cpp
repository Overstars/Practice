#include<bits/stdc++.h>
using namespace std;
int val[1005];
int main()
{
	int n,u,v,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	while(m--)
	{
		cin>>u>>v;
		ans+=min(val[u],val[v]);
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *每条边有且只有一次贡献
 *直觉上,该贡献最小值为两端值较小的那个
 *可以在图上找到最小的点,先计算该点对答案的贡献,并删去该点
 *这样每条边都可以取得最小贡献
 */
