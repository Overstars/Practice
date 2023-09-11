#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll gcd(ll a,ll b)
{
	if(a<b)
		swap(a,b);
	ll r;
	while((r=a%b)){
		a=b;
		b=r;
	}
	return b;
}
ll lcm(ll a,ll b)
{
	return (a*b)/gcd(a,b);
}
ll a[maxn],dp[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,one=0,rec=inf;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][i]=a[i];
		if(a[i]==1)
			one++;
	}
	if(one)
	{
		cout<<n-one<<endl;
		exit(0);
	}
	for(int len=2;len<=n;len++)
	{
		for(int l=1,r=l+len-1;r<=n;l++,r=l+len-1)
		{//dp[l][r]表示[l,r]区间的gcd
			dp[l][r]=gcd(dp[l][r-1],dp[r][r]);
			if(dp[l][r]==1)
			{//消耗len-1得到1,n-1步将1推到左右端
				cout<<n+len-2<<endl;
				exit(0);
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}


