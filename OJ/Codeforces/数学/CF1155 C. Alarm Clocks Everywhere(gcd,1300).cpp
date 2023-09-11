#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
long long gcd(long long a,long long b)
{
	if(a<b)
		swap(a,b);
	long long r;
	while((r=a%b)){
		a=b;
		b=r;
	}
	return b;
}
long long lcm(long long a,long long b)
{
	return (a*b)/gcd(a,b);
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
	ll n,m;
	cin>>n>>m;
	vector<ll>x(n,0),p(m);
	for(int i=0;i<n;i++)
		cin>>x[i];
	ll g=x[1]-x[0];
	for(int i=2;i<n;i++)
		g=gcd(g,x[i]-x[i-1]);
	for(int i=0;i<m;i++)
		cin>>p[i];
	for(int i=0;i<m;i++)
		if(g%p[i]==0)
		{
			cout<<"YES\n"<<x[0]<<' '<<i+1<<endl;
			exit(0);
		}
	cout<<"NO\n";
	return 0;
}


