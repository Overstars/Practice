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
ll d[maxn];
void show(int num,ll len,bool f)
{
	printf("+");
	for(int i=1;i<=len;i++)
		printf("-");
	printf("+\n");
	printf("|");
	for(int i=1;i<=len;i++)
		printf("%c",(i==len&&f)?'*':' ');
	printf("|%d\n",num);
	printf("+");
	for(int i=1;i<=len;i++)
		printf("-");
	printf("+\n");
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	ll maxd=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		maxd=max(maxd,d[i]);
	}
	for(int i=1;i<=n;i++)
	{
		ll len=(50*d[i])/maxd;
		if((50*d[i])%maxd)
			len++;
		show(d[i],len,d[i]==maxd);
	}
	return 0;
}


