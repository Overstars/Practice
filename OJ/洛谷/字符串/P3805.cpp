#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e7+10;
int cnt[maxn];
int manacher(string s)
{
	int ans=0,MaxR=0,flag=0;
	for(int i=0;i<s.length();i++)
	{
		if(i<MaxR)
			cnt[i]=min(cnt[2*flag-i],MaxR-i);
		else
			cnt[i]=1;
		while(s[i-cnt[i]]==s[i+cnt[i]])
			cnt[i]++;
		if(cnt[i]>cnt[flag])
		{
			ans=cnt[i];
			flag=i;
		}
	}
	return ans-1;
}
int main()
{
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s,t;
	cin>>s;
	t+="$#";
	for(char &ch:s)
	{
		t+=ch;
		t+='#';
	}
	cout<<manacher(t)<<endl;
	return 0;
}
