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
		for(int i=1;i<=n;i++)
			add(i,a[i]-a[i-1]);//�������c����
	}
	void add(int k,int val)//�޸�:a[k]����val,ֱ����c�����ϲ���
	{
		while(k<=n)
		{
			this->c[k]+=val;
			k+=lowbit(k);
		}
	}
	void range_update(int l, int r, int val)//�������
	{
		add(l,val);//��l֮�����еĵ㶼����һ��
		add(r+1,-val);//��Ϊr֮��ĵ��ǲ��ø��µģ����Ƕ�����ˣ�����Ҫÿ���㶼-val��
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
//		bit.add(i,a[i]-a[i-1]);//ά��һ���������
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
