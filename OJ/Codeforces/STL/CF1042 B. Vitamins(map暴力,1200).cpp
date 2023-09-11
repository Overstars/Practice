#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int c[1005];
map<string,int> QAQ;
inline int com(string a,string b)
{
	if(!QAQ[a]||!QAQ[b])
		return inf;
	return QAQ[a]+QAQ[b];
}
int solve()
{
	int ans=inf;
	if(QAQ["A"]&&QAQ["B"]&&QAQ["C"])
		ans=QAQ["A"]+QAQ["B"]+QAQ["C"];
	if(QAQ["ABC"])
		ans=min(ans,QAQ["ABC"]);
	ans=min(ans,com("A","BC"));
	ans=min(ans,com("AB","C"));
	ans=min(ans,com("AC","B"));
	ans=min(ans,com("AB","BC"));
	ans=min(ans,com("AC","BC"));
	ans=min(ans,com("AB","AC"));
	if(ans==inf)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
}
int main()
{
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>s;
		sort(s.begin(),s.end());
		if(QAQ[s]==0)
			QAQ[s]=c[i];
		else
			QAQ[s]=min(QAQ[s],c[i]);
	}
	solve();
	return 0;
}
