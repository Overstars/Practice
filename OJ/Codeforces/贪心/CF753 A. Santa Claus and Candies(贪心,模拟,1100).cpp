#include<bits/stdc++.h>
using namespace std;
int ans[1005]={0};
int main()
{
	int n,cnt=0,tot=0;
	cin>>n;
	for(int i=1;tot<n;i++)
	{
		if(n-tot<i)//不够发出这一个
		{
			ans[i-1]+=n-tot;
			tot=n;
			break;
		}
		cnt++;
		tot+=i;
		ans[i]=i;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<ans[i]<<' ';
	return 0;
}
