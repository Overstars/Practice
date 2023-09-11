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
ll ans[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int k,a,b;
	cin>>n>>m>>k;
	vector<pii>f(k);
	for(auto &i:f)
		cin>>i.ff>>i.ss;
	map<pii,bool>vis;
	memset(ans,INF,sizeof(ans));
	int x=0,y=0,ox=1,oy=1;//ox控制上下,oy控制左右
	while(!vis[pii(x,y)])
	{
		vis[pii(x,y)]=1;
		if(y+oy*n>0||y+oy*n<m)
		{//不会撞墙
			x+=ox*n;
			y+=oy*n;
			ox*=-1;
		}
		else if(y+oy*n>=m)
		{
			oy*=-1;//向左

			ox*=-1//
		}

	}
	return 0;
}
/*
 * 2021-06-03-22.23.37
 * C:\Users\dell\Desktop\2021年6月3日Intel Code Challenge Final Round (Div. 1 + Div. 2, Combined)\C.cpp
 *
*/

