//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define fi first
#define se second
const int maxn=505,inf=0x3f3f3f3f,mod=1000000007;
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
bool vis[maxn][maxn],ok[maxn];
int h[maxn][maxn],nx[]={-1,1,0,0},ny[]={0,0,1,-1};
pii bfs(int st,int n,int m)
{
	int l=inf,r=0;
	queue<pii>QAQ;
	QAQ.push({1,st});
	while(!QAQ.empty())
	{
		pii x=QAQ.front();
		QAQ.pop();
		vis[x.fi][x.se]=1;
		for(int i=0;i<4;i++)
		{
			int xx=x.fi+nx[i],yy=x.se+ny[i];
			if(vis[xx][yy]||h[xx][yy]>=h[x.fi][x.se])
				continue;
			if(xx<1||xx>n||yy<1||yy>m)
				continue;
			vis[xx][yy]=1;
			QAQ.push({xx,yy});
		}
		if(x.fi==n)
		{
			ok[x.se]=1;
			l=min(l,x.se);
			r=max(r,x.se);
		}
	}
	return make_pair(l,r);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>h[i][j];
	vector<pii>rec;
	for(int i=1;i<=m;i++)
	{
		if(h[1][i]>=h[1][i-1]&&h[1][i]>=h[1][i+1])
		{
			fill(vis[0],vis[0]+(n+1)*maxn,0);
			rec.push_back(bfs(i,n,m));
		}
	}
	int cnt=0;
	for(int i=1;i<=m;i++)
		if(!ok[i])
			cnt++;
	if(cnt)
		return cout<<0<<'\n'<<cnt<<endl,0;
	sort(rec.begin(),rec.end());
//	for(auto &x:rec)
//		printf("l=%d,r=%d\n",x.fi,x.se);
	int ans=0,ind=0,ed=1;//最小区间覆盖
	while(ed<=m)
	{
		if(rec[ind].fi>ed)
			break;//无解
		int tmp=0;
		for(;ind<rec.size()&&rec[ind].fi<=ed;ind++)
			if(rec[ind].se>tmp)
				tmp=rec[ind].se;
		ed=tmp+1;
		ans++;
	}
	cout<<1<<'\n'<<ans<<endl;
	return 0;
}


