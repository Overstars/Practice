#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//�������,<<setiosflags(ios::fixed)<<setprecision(9)
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
//#define DEBUG
struct BinaryIndexedsTree
{
	int c[maxn],n;
	inline int lowbit(int x)
	{
		return x & (-x);
	}
	void build(int *a,int n)//a��ԭ����,n��Ԫ�ظ���
	{
		this->n=n;
		memset(c,0,sizeof(c));
		for(int i=1;i<=this->n;i++)
			add(i,a[i]);
	}
	void add(int k,int num)//�޸�:a[k]����num,ֱ����c�����ϲ���
	{
		while(k<=this->n)
		{
			this->c[k]+=num;
			k+=lowbit(k);
		}
	}
	void range_update(int l, int r, int val)//�������
	{
		add(l, val);//��l֮�����еĵ㶼����һ��
		add(r + 1, -val);//��Ϊr֮��ĵ��ǲ��ø��µģ����Ƕ�����ˣ�����Ҫÿ���㶼-val��
	}
	int read(int k)//��ѯ:1~k�������
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
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	bit.build(a,n);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1)
		{
			bit.add(b,c);
		}
		else{
			printf("%d\n",bit.read(c)-bit.read(b-1));
		}
	}
	return 0;
}
