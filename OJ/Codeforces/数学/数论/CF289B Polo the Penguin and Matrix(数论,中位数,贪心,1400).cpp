#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int a[maxn];
int main()
{
	int n,m,d;
	cin>>n>>m>>d;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+n*m+1);
	int sub=0;
	bool flag=1;
	for(int i=n*m;i>=1;i--)
	{
		a[i]-=a[1];//留下差值
		if(a[i]%d)//做不到
		{
			flag=0;
			break;
		}
		sub+=a[i];//可以通过d弥补
	}
	if(!flag)
		cout<<-1<<endl;
	else{//通过加减d使得a[1,n]所有数变得一样
		int tar=a[n*m/2+1];//为什么总是这个?
//		int tar=sub/(n*m);
//		if(tar%d)
//		{
//			if(2*(tar-d*(tar/d))<=d)
//				tar=d*(tar/d);
//			else
//				tar=d*(tar/d+1);
//		}
//		cout<<"tar="<<tar<<endl;
		int ans=0;
		for(int i=1;i<=n*m;i++)
		{
			ans+=abs(tar-a[i])/d;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
 0 1 4 4 6 99
 */
