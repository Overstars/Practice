#include<bits/stdc++.h>
using namespace std;
int w[10005];
int main()
{
	int n,m,ans=0,i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>w[i];
	priority_queue<int,vector<int>,greater<int> >QAQ;
	for(i=1;i<=m;i++)
		QAQ.push(w[i]);
	for(;i<=n;i++)
	{
		int tem=QAQ.top();
		QAQ.pop();
		QAQ.push(w[i]+tem);
	}
	while(!QAQ.empty())
	{
		ans=max(ans,QAQ.top());
		QAQ.pop();
	}
	cout<<ans<<endl;
	return 0;
}
