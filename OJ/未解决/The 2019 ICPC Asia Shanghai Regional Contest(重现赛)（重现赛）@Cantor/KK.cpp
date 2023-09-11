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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int T,n,m,u,v;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		vector<pii>rec;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			u--,v--;
			rec.push_back(pii(u,v));
		}
		int ans=0;
//		cout<<bitset<32>((1ll<<n)-1)<<endl;
		for(int i=0;i<(1ll<<n);i++)
		{
			int now=0;
//			cout<<"rec = "<<rec.size()<<endl;
			for(pii &e:rec)
			{
				int a=i&(1ll<<e.ff);
				int b=i&(1ll<<e.ss);
//				printf("a = %d,b = %d\n",a,b);
				if((!a&&b)||(a&&!b))
					now++;
			}
			ans=max(ans,now);
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
/*
5 5
1 2
2 3
3 4
4 5
5 1
*/
/*
 * 2021-04-28-16.41.34
*/

