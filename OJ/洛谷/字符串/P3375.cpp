#include<bits/stdc++.h>
using namespace std;
int nex[1000005];
void getnext(string &s)
{
	for(int i=1,j=0;i<s.length();i++)
	{
		while(j>0&&s[i]!=s[j])
			j=nex[j-1];
		if(s[i]==s[j])
			j++;
		nex[i]=j;
	}
}
vector<int> kmp(string &s,string &t)
{
	vector<int>ans;
	for(int i=0,cmp=0;i<s.length();i++)
	{
		while(cmp>0&&s[i]!=t[cmp])
			cmp=nex[cmp-1];
		if(s[i]==t[cmp])
			cmp++;
		if(cmp==t.length())
		{
			ans.push_back(i-(int)t.length()+2);
			cmp=nex[cmp-1];
		}
	}
	return ans;
}
int main()
{
	string s,t;
	cin>>s>>t;
	getnext(t);
	vector<int> ans=kmp(s,t);
	for(int &i:ans)
		cout<<i<<endl;
	for(int i=0;i<t.length();i++)
		cout<<nex[i]<<' ';
	return 0;
}
