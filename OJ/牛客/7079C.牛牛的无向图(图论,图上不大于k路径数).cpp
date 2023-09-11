//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
unsigned int SA, SB, SC;
int n, m, q, LIM;
unsigned int rng61(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
int u[maxn],v[maxn],w[maxn],L[maxn*5],ans[maxn*5];
void gen(){
    scanf("%d%d%d%u%u%u%d", &n, &m, &q, &SA, &SB, &SC, &LIM);
    for(int i = 1; i <= m; i++){
        u[i] = rng61() % n + 1;
        v[i] = rng61() % n + 1;
        w[i] = rng61() % LIM;
    }
//    for(int i=1;i<=100;i++)
//		printf("%d:%u\n",i,rng61());
    for(int i = 1; i <= q; i++){
        L[i] = rng61() % LIM;
    }//q个数对应的答案异或
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	gen();

	return 0;
}


