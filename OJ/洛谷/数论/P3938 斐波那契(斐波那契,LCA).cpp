#include<bits/stdc++.h>
using namespace std;
#define int long long
int fibo[62]={1,1};
signed main()
{
	for(int i=2;i<62;i++)
		fibo[i]=fibo[i-1]+fibo[i-2];
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		while(a!=b)
		{
			if(a<b)
				swap(a,b);
			int gene=lower_bound(fibo,fibo+62,a)-fibo;//找到第一个不比a小的,记录编号,编号x即a为第x代
			a-=fibo[gene-1];//减去上一代总数,此时a为父节点编号
		}
		cout<<a<<endl;
	}
	return 0;
}
