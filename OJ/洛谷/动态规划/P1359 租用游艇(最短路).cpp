#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=220,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int d[maxn][maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			cin>>d[i][j];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=i;k<=j;k++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	cout<<d[1][n]<<endl;
	return 0;
}


