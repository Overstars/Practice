//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll ans=0;
struct node
{
	int w[5];
	node(){}
	node(int a,int b,int c,int d)
	{
		w[1]=a;
		w[2]=b;
		w[3]=c;
		w[4]=d;
	}
} arr[55][55];
//vector<node>arr[55];
int n,k,cnt[55],nex[55];
//ll sum[55][5],MAX[55][5];
void dfs(int x,ll a,ll b,ll c,ll d)
{
	if(x>k)
	{
		ans=max(ans,a*b*c*d);
		return;
	}
	//	printf("x=%d,%d,%d,%d,%d\n",x,a,b,c,d);
//	for(node &i:arr[x])
//		dfs(x+1,a+i.w[1],b+i.w[2],c+i.w[3],d+i.w[4]);
	for(int i=1;i<=cnt[x];i++)
		dfs(nex[x],a+arr[x][i].w[1],b+arr[x][i].w[2],c+arr[x][i].w[3],d+arr[x][i].w[4]);
	return;
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int T,t,a,b,c,d;
//	cin>>T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
//		read(n,k);
//		cin>>n>>k;
		for(int i=1;i<=k;i++)
		{
//			arr[i].clear();
			cnt[i]=0;
		}
//		memset(MAX,0,sizeof(MAX));
//		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&t);
			cnt[t]++;
			for(int j=1;j<=4;j++)
				scanf("%d",&arr[t][cnt[t]].w[j]);
//			read(t,a,b,c,d);
//			cin>>t>>a>>b>>c>>d;
//			arr[t].push_back({a,b,c,d});
//			for(int j=1;j<=4;j++)
//				MAX[i][j]=max(MAX[i][j],(ll)arr[t][arr[t].size()-1].w[j]);
		}
		int pre=k+1;
		for(int i=k;i>=1;i--)
		{
			if(cnt[i])
			{
				nex[i]=pre;
				pre=i;
			}
		}
//		for(int i=k;i>=1;i--)
//			for(int j=1;j<=4;j++)
//				sum[i][j]=sum[i+1][j]+MAX[i][j];
		ans=0;
		dfs(pre,100,100,100,100);
		printf("%lld\n",ans);
//		cout<<ans<<endl;
	}
	return 0;
}


