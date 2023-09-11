#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0;
	string s,t;
	cin>>n>>s>>t;
	for(int i=0;i<n;i++)
	{
		if(s[i]!=t[i]&&s[i+1]!=t[i+1]&&s[i]!=s[i+1])
			ans++,i++;
		else if(s[i]!=t[i])
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
