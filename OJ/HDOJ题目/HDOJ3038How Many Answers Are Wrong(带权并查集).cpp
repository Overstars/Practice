#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//�������,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1000005;
int fa[maxn],val[maxn];
int Find(int x)
{
	if(x!=fa[x])
	{
		int tem=fa[x];
		fa[x]=Find(fa[x]);
		val[x]+=val[tem];
	}
	return fa[x];
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n,m;
	while(cin>>n>>m)//n����,m������
	{
		for(int i=0;i<=n;i++)
			fa[i]=i;
		memset(val,0,sizeof(val));
		int cnt=0;
		while(m--)
		{
			int x,y,z;
			cin>>x>>y>>z;
			x--;//ע�����x��
			int px=Find(x),py=Find(y);
			if(px==py)//���Ȩֵ��Ϊ���Ļ�,�ӽڵ��Ȩֵ�����
			{
				if(val[x]-val[y]!=z)
					cnt++;
			}
			else{//���뵽��ȷ�ļ�����
				fa[px]=py;//���������ҽڵ���
				val[px]=-val[x]+val[y]+z;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
