#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//¿ØÖÆÊä³ö,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>
#define lowbit(x) ((x) & -(x))
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=10000005;
int a[maxn],c[maxn],n;
void add(int k,int val)
{
	while(k<=n)
	{
		c[k]+=val;
		k+=lowbit(k);
	}
}
void rangeadd(int l,int r,int val)
{
	add(l,val);
	add(r+1,-val);
}
int ask(int x)
{
	int ans=0;
	while(x)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
//#define DEBUG
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
	int m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a;
		if(a==0)
		{
			cin>>b>>c;
			rangeadd(b,c,1);
		}
		else{
			cin>>b;
			cout<<ask(b)<<endl;
		}
	}
	return 0;
}
