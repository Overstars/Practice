#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
char s[maxn];
int a[maxn],b[maxn];
int main()
{
	int n,k;
	cin>>n>>k>>s+1;
	for(int i=1;i<=n;i++)//前缀和
	{
		a[i]=a[i-1];
		b[i]=b[i-1];
		if(s[i]=='a')
			a[i]++;
		else
			b[i]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)//以i为起点,修改k个为s[i]的最长长度
		ans=max(ans,max(upper_bound(b+1,b+n+1,b[i-1]+k)-(b+i),ans=max(ans,upper_bound(a+1,a+n+1,a[i-1]+k)-(a+i))));
	cout<<ans<<endl;
	return 0;
}
