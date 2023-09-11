#include<bits/stdc++.h>
using namespace std;
int lg[20005];
int pow(int x,int n)
{
	int ret=1;
	while(n)
	{
		if(n&1)
			ret*=x;
		x*=x;
		n>>=1;
	}
	return ret;
}
void solve(int x)
{
	if(x<=0)
		return;
	if(lg[x]==0)
		cout<<"2(0)";
	if(lg[x]==1)
		cout<<"2";
	if(lg[x]>1)
	{
		cout<<"2(";
		solve(lg[x]);
		cout<<")";
	}
	if(pow(2,lg[x])<x)
	{
		cout<<"+";
		solve(x-pow(2,lg[x]));
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		lg[i]=lg[i-1]+(1<<(lg[i-1]+1)==i);
//		cout<<i<<":"<<lg[i]<<endl;
	}
	solve(n);
	return 0;
}
