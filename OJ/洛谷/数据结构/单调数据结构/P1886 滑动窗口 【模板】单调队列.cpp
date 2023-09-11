#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn],d[maxn][20],lg[maxn];
void init(int n,bool MAX)
{//d[i][j]表示以i为起点,2^j长度的最值
	for(int i=1;i<=n;i++)
	{
		lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
		d[i][0]=a[i];
	}
	for(int j=1;(1<<j)<=n;j++)//枚举长度
		for(int i=1;i+(1<<j)-1<=n;i++)//枚举起点,倍增+DP
		{
			if(MAX)
				d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
			else
				d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
		}
}
int rmq(int l,int r,bool MAX)
{
	int k=lg[r-l+1];
	return MAX?max(d[l][k],d[r-(1<<k)+1][k]):min(d[l][k],d[r-(1<<k)+1][k]);
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	init(n,0);
	for(int i=k;i<=n;i++)
		cout<<rmq(i-k+1,i,0)<<' ';
	cout<<endl;
	init(n,1);
	for(int i=k;i<=n;i++)
		cout<<rmq(i-k+1,i,1)<<' ';
	cout<<endl;
	return 0;
}


