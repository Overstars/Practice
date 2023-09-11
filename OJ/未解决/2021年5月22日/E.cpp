//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=105,inf=0x3f3f3f3f,mod=1000000007;
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
struct Matrix
{
	ll a[maxn][maxn],r,c;
	Matrix(){}
	Matrix(const Matrix &m)
	{
		this->r=m.r;
		this->c=m.c;
		for(int i=1;i<=m.r;i++)
			for(int j=1;j<=m.c;j++)
				a[i][j]=m.a[i][j];
	}
	Matrix (ll row,ll col):
		r(row),c(col){memset(a,0,sizeof(a));}
};
ostream &operator << (ostream &os,const Matrix m)
{
	for(int i=1;i<=m.r;i++)
	{
		for(int j=1;j<=m.c;j++)
		{
			cout<<m.a[i][j]<<' ';
		}
		cout<<'\n';
	}
	return os;
}
Matrix operator *(const Matrix &m1,const Matrix &m2)
{//矩阵相乘
	Matrix ret(m1.r,m2.c);
	for(int i=1;i<=m1.r;i++)
		for(int k=1;k<=m1.c;k++)
			for(int j=1;j<=m2.c;j++)
				ret.a[i][j]=(ret.a[i][j]+(m1.a[i][k]*m2.a[k][j])%mod)%mod;
	return ret;
}
Matrix operator^(Matrix m,ll k)
{//矩阵m的k次幂
	Matrix ret(m);//重载乘法后和，快速幂一样的...
	k--;
	while(k)
	{
//		cout<<k<<":\nret:\n"<<ret<<"m:\n"<<m<<endl;
		if(k&1)
			ret=ret*m;
		m=m*m;
		k>>=1;
	}
	return ret;
}
ll a[maxn],tmp[maxn][maxn];
signed main(signed argc, char const *argv[])
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
	if(k==1)
		return cout<<n<<endl,0;
	Matrix m(n,n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(__builtin_popcountll(a[i]^a[j])%3==0)
				m.a[j][i]=m.a[i][j]=tmp[i][j]=tmp[j][i]=1;
		}
	}
	k--;
	Matrix now=m^k;
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			ans+=now.a[i][j];
			ans%=mod;
		}
	cout<<ans<<endl;
	return 0;
}
/*
 * 2021-05-22-16.23.00
 * C:\Users\dell\Desktop\C++\OJ\未解决\2021年5月22日\E.cpp
 * 4144 4062 3980
*/

