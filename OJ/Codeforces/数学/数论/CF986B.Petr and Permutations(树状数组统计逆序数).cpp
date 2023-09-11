#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lowbit(x) (x&(-x))
const int maxn=1000005;
int a[maxn],c[maxn];
void updata(int x,int num,int n)
{
	while(x<=n)
	{
		c[x]+=num;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int sum=0;
	while(x)
	{
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int cnt=0;
	for(int i=n;i>0;i--)
	{
		cnt+=query(a[i]);
		updata(a[i],1,n);
	}
	if((cnt&1)^((3*n)&1))
		cout<<"Um_nik"<<endl;
	else
		cout<<"Petr"<<endl;
	return 0;
}
