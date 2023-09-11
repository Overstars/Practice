#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
char st[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
	ll n,m,tem[30],len;//将一个n进制数转化为m进制
	string str;
	cin>>n>>str>>m;
	for(len=0;len<str.size();len++)
		if(isdigit(str[len]))
			tem[len]=str[len]-'0';
		else
			tem[len]=(str[len]-'A')+10;
	ll sum=0,r=1;//存放对应的十进制数的值
	for(ll i=len-1;i>=0;i--)
	{
		sum+=tem[i]*r;
		r*=n;//m的对应次幂
	}
	stack<ll>ans;
	while(sum>0)
	{
		ans.push(sum%m);
		sum/=m;
	}
	while(!ans.empty())
	{
		printf("%c",st[ans.top()]);
		ans.pop();
	}
	return 0;
}
