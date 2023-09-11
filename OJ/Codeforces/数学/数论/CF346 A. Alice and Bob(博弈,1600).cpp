//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,g;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)
			g=a[i];
		else
			g=__gcd(g,a[i]);
	}
	sort(a+1,a+n+1);
	cout<<((a[n]/g-n)%2?"Alice":"Bob")<<endl;
	return 0;
}
/*
 *a1=d=x的等差数列时必败
 *求出得到这个序列的操作次数
 *注:原先的数字不删除
*/
/*
10
72 96 24 66 6 18 12 30 60 48
ans=Bob
*/

