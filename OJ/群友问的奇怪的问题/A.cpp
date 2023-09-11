#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
//char s[maxn];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t,n;
	string s;
	stack<int>stk;
	cin>>n>>s;
	for(auto &ch:s)
	{
		int now=ch-'0';
		if(!stk.empty()&&stk.top()+now==10)
			stk.pop();
		else
			stk.push(now);
	}
	cout<<stk.size()<<endl;
	return 0;
}
/*
 *2021-04-04-19.49.36
*/
