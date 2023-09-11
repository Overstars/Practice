#include<bits/stdc++.h>
using namespace std;
vector<string> v[6];
map<string,bool> mp;
int ans=0;
void dfs(string s,int t)
{
	if(s.length()==t)
	{
		if(!mp[s])
			ans++,mp[s]=1;
		return;
	}
	string tem;
//	tem+=s[0];
//	for(int i=0;i<s.length();i++)
//	{
		int p=s[0]-'a';
		for(auto &j:v[p])
			dfs(tem+j+s.substr(1),t);
//		tem+=s[i];
//	}
}
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=q;i++)
	{
		string str;
		char ch;
		cin>>str>>ch;
		v[ch-'a'].push_back(str);
	}//注意只能替换最前面两个字符
	string s="a";
	dfs(s,n);
	cout<<ans<<endl;
	return 0;
}
