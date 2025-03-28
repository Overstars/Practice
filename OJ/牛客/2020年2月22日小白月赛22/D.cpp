#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
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
	int x,y;
} a[15];
int n,sx,sy,ans;
int dis(int x1,int y1,int x2,int y2)
{
	return abs(x1-x2)+abs(y1-y2);
}
int dis(int s,int t)
{
	if(s==0)//s是起点
		return abs(sx-a[t].x)+abs(sy-a[t].y);
	return abs(a[s].x-a[t].x)+abs(a[s].y-a[t].y);
}
bool vis[maxn];
//queue<int>q;
void dfs(int t,int tim,int tot)
{
	if(tim==n)
	{
		ans=min(ans,tot+dis(sx,sy,a[t].x,a[t].y));
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(i,tim+1,tot+dis(t,i));
			vis[i]=0;
		}
	}
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
	int t,r,c;
	cin>>t;
	while(t--)
	{
		cin>>r>>c>>sx>>sy>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y;
		ans=inf;
		dfs(0,0,0);
		cout<<"The shortest path has length "<<ans<<endl;
	}
	return 0;
}


