//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
int f[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int k;
	cin>>k;
	char now='a';
	for(int i=2;i<=500;i++)
		f[i]=i*(i-1)/2;
	if(k==0)
		return cout<<'a'<<endl,0;
	while(k>0)
	{
		int len=upper_bound(f+2,f+500,k)-f-1;
//		printf("len = %d,c= %d\n",len,f[len]);
		for(int i=1;i<=len;i++)
			cout<<now;
		now++;
		k-=f[len];
	}
	return 0;
}
/*
 * 2021-05-02-15.53.29
 * 感觉似乎是2的幂次贪心
 * 连续相同的贡献len(len-1)/2
*/

