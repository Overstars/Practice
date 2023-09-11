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
	ll x;
	cin>>x;
	ll M=x,a=1,b=x,tmp=x;
	for(ll i=2;i*i<x;i++)
	{
		if(x%i)
			continue;
		ll tb=x/i;
		if(M>max(i,tb)&&lcm(i,tb)==x)
		{
			M=max(i,tb);
			a=i;
			b=tb;
		}
	}
//	vector<ll>rec;
//	for(ll i=2;i*i<=tmp;i++)
//	{
//		if(tmp%i==0)
//		{
//			rec.push_back(i);
//			tmp/=i;
//			while(tmp%i==0)
//				tmp/=i;
//		}
//	}
//	if(tmp>1)
//		rec.push_back(tmp);
//	for(auto &i:rec)
//	{
//		if(lcm(i,x/i)==x)
//		{
//			if(M>max(i,x/i))
//			{
//				M=max(i,x/i);
//				a=i;
//				b=x/i;
//			}
//		}
//	}
	cout<<a<<' '<<b<<endl;
	return 0;
}


