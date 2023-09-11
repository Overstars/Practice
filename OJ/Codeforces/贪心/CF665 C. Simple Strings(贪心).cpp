#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i-1]==s[i])
			for(int j=0;j<26;j++)
				if(s[i-1]!='a'+j&&s[i+1]!='a'+j)
				{
					s[i]='a'+j;
					break;
				}
	}
	cout<<s<<endl;
	return 0;
}
