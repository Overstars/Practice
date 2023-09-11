#include<iostream>
using namespace std;
#define lowbit(x) x&(-x)
const int maxn=100005;
int c[maxn];
void update(int x,int num,int n)
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
	int n,w,a,b;
	char ch;
	cin>>n>>w;
	while(w--)
	{
		cin>>ch>>a>>b;
		if(ch=='x')
			update(a,b,n);
		else
			cout<<query(b)-query(a-1)<<endl;
	}
	return 0;
}
