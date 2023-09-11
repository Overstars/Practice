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
int a[maxn],tar;
ll dist[maxn]={-1};
map<ll,int>mp;
bool vis[maxn];
vector<int>rec,cir;
void dfs(int x,int fa)
{
//	printf("%d\n",x);
	if(!vis[x])
		cir.push_back(x);
	if(vis[x])
	{
		tar=x;
		bool flag=0;
		for(int i=0;i<cir.size();i++)
		{
			if(cir[i]==x)
				flag=1;
			if(flag)
			{
				rec.push_back(cir[i]);
//				printf("%d,",cir[i]);
			}
		}
//		printf("\n");//
//		rec.erase(rec.find(rec.begin(),rec.end(),x),rec.end());
		return;
	}
	vis[x]=1;
	dist[x]=dist[fa]+1;
	mp[dist[x]]=x;
	dfs(a[x],x);
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0);
	if(k<=dist[tar])
		cout<<mp[k]<<endl;
	else{
		k-=dist[tar];
		ll len=rec.size();
		cout<<rec[k%len]<<endl;
	}
	return 0;
}


