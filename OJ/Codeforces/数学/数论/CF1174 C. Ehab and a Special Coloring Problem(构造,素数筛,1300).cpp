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
ll arr[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,tot=0;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(arr[i])
			continue;
		tot++;
		for(int j=i;j<=n;j+=i)
			if(arr[j]==0)
				arr[j]=tot;
	}
	for(int i=2;i<=n;i++)
		cout<<arr[i]<<' ';
	return 0;
}

/*
 *
 */
