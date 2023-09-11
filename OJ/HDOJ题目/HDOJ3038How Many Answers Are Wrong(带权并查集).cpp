#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
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
	while(cin>>n>>m)//n个数,m个问题
	{
		for(int i=0;i<=n;i++)
			fa[i]=i;
		memset(val,0,sizeof(val));
		int cnt=0;
		while(m--)
		{
			int x,y,z;
			cin>>x>>y>>z;
			x--;//注意包括x点
			int px=Find(x),py=Find(y);
			if(px==py)//如果权值都为正的话,子节点的权值会更大
			{
				if(val[x]-val[y]!=z)
					cnt++;
			}
			else{//加入到正确的集合里
				fa[px]=py;//左结点连在右节点下
				val[px]=-val[x]+val[y]+z;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
