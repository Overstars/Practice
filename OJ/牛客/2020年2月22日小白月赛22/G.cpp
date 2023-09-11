#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=105,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int mp[maxn][maxn];
int dis(int x1,int y1,int x2,int y2)
{
	return abs(x1-x2)+abs(y1-y2);
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j];
		int ans=inf;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				int now=0;
				for(int k=1;k<=n;k++)
					for(int l=1;l<=m;l++)
						now+=mp[k][l]*dis(i,j,k,l);
				ans=min(ans,now);
			}
		cout<<ans<<endl;
	}
	return 0;
}


