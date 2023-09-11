#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,ans=1;
	cin>>n>>k;
	int len=2*k+1;
	ans=n/len;
	if(n%len)
		ans++;
	cout<<ans<<endl;
	if(n%len==0)
	{
		int pos=k+1;
		while(ans--)
		{
			cout<<pos<<' ';
			pos+=len;
		}
	}
	else{
		int pos=1;
//		printf("rem=%d\n",n%len);
		if(n%len>pos+k)//不在1的覆盖范围内,调整初始位置
		{
			pos+=n%len-k;
		}
		while(ans--)
		{
			cout<<pos<<' ';
			pos+=len;
		}
	}
	return 0;
}
