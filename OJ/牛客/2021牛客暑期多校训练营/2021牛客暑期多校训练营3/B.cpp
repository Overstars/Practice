#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=5002,inf=0x3f3f3f3f,mod=1000000007;
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
//int mp[maxn][maxn],val[maxn*maxn];
struct node
{
	int x,y,val;
	node(){}
	node(int x,int y,int z):
		x(x),y(y),val(z){}
};
int fa[maxn+maxn];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
		fa[b]=a;
	else
		fa[a]=b;
	return 1;
}
node vec[maxn*maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,a,b,c,d,p;
//	iota(fa,fa+maxn,0);
//	for(int i=1;i<=10;i++)
//		cerr<<"fa = "<<fa[i]<<endl;
//	auto cmp=[](const node &a,const node &b){return a.val>b.val;};
//	priority_queue<node,vector<node>,decltype(cmp)>pq(cmp);
	#define mach
	#ifdef mach
	cin>>n>>m>>a>>b>>c>>d>>p;
	for(int i=1;i<=n+m;i++)
		fa[i]=i;
//	vector<int> row(n+1,0),col(m+1,0);
//	vector<node>vec;
//	val[0]=a;
	ll pre=a;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			pre=((ll)pre*pre*b+pre*c+d)%p;
			vec[(i-1)*m+j]=node(i,j,pre);
//			vec.push_back(node(i,j,pre));
	//		val[i]=(val[i-1]*val[i-1]*b+val[i-1]*c+d)%p;
		}
//	vector<node> vec;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//		{
////			mp[i][j]=val[m*(i-1)+j];
////			fprintf(stderr,"%d%c",mp[i][j],((j==m)?'\n':' '));
////			puts("");
////			vec.emplace_back(node(i,j,mp[i][j]));
////			pq.push(node(i,j,mp[i][j]));
//		}
	#else
	cin>>n>>m;
	vector<int> row(n+1,0),col(m+1,0);
	for(int i=1;i<=n;i++)
		for(int j=1,tmp;j<=m;j++)
		{
			cin>>tmp;
			pq.push(node(i,j,tmp));
		}
	#endif // mach
//	cerr<<"pq = "<<pq.size()<<endl;
//	priority_queue<node,vector<node>,function<bool(const node&,const node&)> >pq(cmp);
	sort(vec+1,vec+n*m+1,[](const node &a,const node &b){
			return a.val<b.val;
		});
	int cnt=0,ans=0;
	for(int i=1;i<=n*m&&cnt<n+m-1;i++)
	{
		node &now=vec[i];
		if(findfa(now.x)!=findfa(now.y+n))
		{
//			fprintf(stderr,"x = %lld, y = %lld, val = %lld, ans = %lld\n",now.x,now.y,now.val,ans);
			cnt++;
			Merge(now.x,now.y+n);
			ans+=now.val;
		}
	}
//	do{
//		node now=pq.top();
//		pq.pop();
//		if(findfa(now.x)!=findfa(now.y+n))
//		{
////			fprintf(stderr,"x = %lld, y = %lld, val = %lld, ans = %lld\n",now.x,now.y,now.val,ans);
//			cnt++;
//			Merge(now.x,now.y+n);
//			ans+=now.val;
//		}
////		if(row[now.x]<2||col[now.y]<2)
////		{
////			fprintf(stderr,"x = %lld, y = %lld, val = %lld, ans = %lld\n",now.x,now.y,now.val,ans);
////			row[now.x]++;
////			col[now.y]++;
////			ans+=now.val;
////			cnt++;
////		}
//	}while(cnt<n+m-1&&!pq.empty());
	if(cnt!=n+m-1)
		cerr<<cnt<<" != "<<n+m-1<<endl;
	cout<<ans<<endl;
	return 0;
}
/*
2 4 6 3
3 3 3 10
3 3 3 10
3 3 3 10
*/
/*
 * 2021-07-24-12.40.09
 * C:\Users\dell\Desktop\C++\OJ\牛客\2021牛客暑期多校训练营\2021牛客暑期多校训练营3\B.cpp
 *
*/

