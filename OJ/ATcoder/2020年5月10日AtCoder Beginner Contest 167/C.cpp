#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=20,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int c[maxn],a[maxn][maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,x,ans=inf;
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	}
	bool ok=1;
	for(int i=1;i<=m;i++)
	{
		int now=0;
		for(int j=1;j<=n;j++)
			now+=a[j][i];
		if(now<x)
			ok=0;
	}
	if(!ok)
		cout<<-1<<endl;
	else{//枚举n本书
		for(int i=0;i<=(1<<n)-1;i++)
		{
			int cost=0;
			vector<int>rec(m+1,0);
			for(int j=0;(1<<j-1)<=i;j++)
			{
				if(i&(1<<j-1))//要买第j本
				{
					cost+=c[j];
					for(int k=1;k<=m;k++)
						rec[k]+=a[j][k];
				}
			}
			bool flag=1;
			for(int j=1;j<=m;j++)
				if(rec[j]<x)
				{
					flag=0;
					break;
				}
			if(flag)
				ans=min(ans,cost);
		}
		cout<<ans<<endl;
	}
	return 0;
}


