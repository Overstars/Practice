#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];
int main()
{//非递减数列,求区间众数
	int n,q;
	while(cin>>n&&n)
	{
		cin>>q;
		for(int i=1;i<=n;i++)
			cin>>a[i];
	}
	return 0;
}
