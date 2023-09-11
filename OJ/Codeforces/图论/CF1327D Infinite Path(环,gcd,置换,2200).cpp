//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int p[maxn],c[maxn];
vector<int>G[maxn];
bitset<maxn>vis;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vis.reset();
		for(int i=1;i<=n;i++)
			G[i].clear();
		for(int i=1;i<=n;i++)
		{
			cin>>p[i];
			G[i].push_back(p[i]);
		}
		for(int i=1;i<=n;i++)
			cin>>c[i];
		int ans=inf;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])//所在环未被枚举
			{
				vector<int>col,f;
				vis[i]=1;
				col.push_back(c[i]);//环上所有点颜色
				for(int v=p[i];v!=i;v=p[v])
					col.push_back(c[v]),vis[v]=1;
				int siz=col.size(),k=inf;
				for(int j=1;j<=siz;j++)
					if(siz%j==0)//环长的因数
						f.push_back(j);
//				ans=min(ans,siz);//转一整圈,转到自身
				for(int &x:f)
				{
					bool ok=0;
					for(int s=0;s<x;s++)
					{
						bool same=1;
						for(int j=s;j<siz;j+=x)
							if(col[j]!=col[s])
							{
								same=0;
								break;
							}
						if(same)
						{//存在合法情况
							ok=1;
							break;
						}
					}
					if(ok)
					{//记录并计算其他环的答案
						ans=min(ans,x);
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
 *可以发现p数组在做[下标]->[数值]的转化时一定会形成环
 *进行一次操作相当于将每个箭头沿其出点向下移动一步
 *如果环上所有c都相同,则k=0
 *否则必须将一个数值转到与下标相同
 *一定有解,解为最小环
 *想歪了
 *对于每个环,枚举跳转次数k
*/
/*
5
5 3 4 2 1
1 2 3 4 5
*/
