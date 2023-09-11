#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=105,mod=1000000007;
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
int main()
{
//	freopen("P3383.in","r",stdin);
	ll n,k;//求n*n矩阵的k次幂
	cin>>n>>k;
	Matrix tem(n,n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>tem.a[i][j];
	Matrix ans=tem^k;
	cout<<ans;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			cout<<ans.a[i][j]<<(j==n)?'\n':' ';
	return 0;
}
