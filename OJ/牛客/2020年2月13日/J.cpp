#include<bits/stdc++.h>
#define PI 3.14159265358979323846
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
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,r,i,j;
	double ans=0;
	cin>>n>>r>>i>>j;
	if(i>j)
		swap(i,j);
	ll dis=min(j-i,n-j+i);
	cout<<setiosflags(ios::fixed)<<setprecision(9)<<dis*2*r*sin((double)PI/n)<<endl;
	return 0;
}


