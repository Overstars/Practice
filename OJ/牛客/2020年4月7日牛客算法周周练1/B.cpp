#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=1010,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
double c[maxn],d[maxn];//初始速度,每轮衰减量
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	double v,u,ans=0;
	cin>>n>>v>>u;//n个人,间隔u米,每个人速度均为v
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		cin>>d[i];
	for(int i=1;i<=n;i++)
	{//第i个人以第j位出发所用时间
		for(int j=1;j<=n;j++)
		{//此人相对于队伍的速度
			ans+=n*u/(c[i]-(j-1)*d[i]-v);
		}
	}
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<ans/n<<endl;
	return 0;
}


