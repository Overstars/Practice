//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
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
struct node
{
	int x,y,cnt;
	node(){}
	node(int x,int y,int c):
		x(x),y(y),cnt(c){}
	bool operator < (const node &b)const
	{//大根堆
		return cnt<b.cnt;
	}
};
int nx[]={0,1,0,-1},ny[]={1,0,-1,0};
map<pii,bool> vis;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,r,k;
	cin>>n>>m>>r>>k;
	ll ans=0;
	priority_queue<node> q;
	int x=(n+1)/2,y=(m+1)/2;
	auto get = [n,m,r](int x,int y)
	{
		int xx=min(n,x+r-1)-max(x,r)+1;
		int yy=min(m,y+r-1)-max(y,r)+1;
		return xx*yy;
	};
	q.push(node(x,y,get(x,y)));
	vis[pii(x,y)]=1;
	while(k--)
	{
		node now=q.top();
		q.pop();
		ans+=now.cnt;
//		cerr<<"cnt = "<<now.cnt<<endl;
		for(int i=0;i<4;i++)
		{
			int xx=now.x+nx[i],yy=now.y+ny[i];
			if(xx>n||xx<1||yy>m||yy<1)
				continue;
			if(vis[pii(xx,yy)])
				continue;
			vis[pii(xx,yy)]=1;
			q.push(node(xx,yy,get(xx,yy)));
		}
	}
	cout<<setiosflags(ios::fixed)<<setprecision(10)<<(double)ans/((ll)(n-r+1)*(m-r+1))<<endl;
	return 0;
}
/*
 *鱼缸为长n宽m的方格,用边长为r的正方形渔网捞鱼
 *放置k条鱼,使得期望最大,并输出这个最大期望
 *计算每个方格可以被矩形覆盖的次数,挑出最大的k个/存在的矩形数目
*/

