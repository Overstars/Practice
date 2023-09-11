#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=500005;
struct BinaryIndexedsTree
{
	int c[maxn],n;
	inline int lowbit(int x)
	{
		return x & (-x);
	}
	void build(int *a,int n)//a是原数组,n是元素个数
	{
		this->n=n;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
			add(i,a[i]-a[i-1]);//构建差分c数组
	}
	void add(int k,int val)//修改:a[k]加上val,直接在c数组上操作
	{
		while(k<=n)
		{
			this->c[k]+=val;
			k+=lowbit(k);
		}
	}
	void range_update(int l, int r, int val)//区间更新
	{
		add(l,val);//把l之后所有的点都更新一遍
		add(r+1,-val);//因为r之后的点是不用更新的，但是多更新了，所以要每个点都-val；
	}
	int read(int k)//查询:1~k的区间和
	{
		int sum=0;
		while(k)
		{
			sum+=this->c[k];
			k-=lowbit(k);
		}
		return sum;
	}
} bit;
int a[maxn];
//https://blog.csdn.net/qq_39562952/article/details/81298043
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
	int n,m;
	cin>>n>>m;
	memset(bit.c,0,sizeof(bit.c));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
//		bit.add(i,a[i]-a[i-1]);//维护一个差分数组
	}
	bit.build(a,n);
	for(int i=1;i<=m;i++)
	{
		int aa,b,c,d;
		cin>>aa;
		if(aa==1)
		{
			cin>>b>>c>>d;
			bit.range_update(b,c,d);
		}
		else{
			cin>>b;
//			printf("%d\n",bit.read(b));
			cout<<bit.read(b)<<endl;
		}
	}
//	for(int i=1;i<=n;i++)
//		cout<<"c["<<i<<"]="<<bit.read(i)<<endl;
	return 0;
}
