#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
vector<int> G[maxn],st;
int dfs(int x)
{
	if(G[x].empty())
		return 1;
	int maxd=0;
	for(auto &v:G[x])
		maxd=max(maxd,dfs(v)+1);
	return maxd;
}
int main()
{
	int n,p,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p;//i的上司p
		if(p==-1)
			st.push_back(i);
		else
			G[p].push_back(i);
	}
	for(auto &x:st)
		ans=max(ans,dfs(x));
	cout<<ans<<endl;
	return 0;
}
