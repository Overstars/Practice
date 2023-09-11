#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=30,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int fa[maxn],siz[maxn];
vector<int>rec[maxn];
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
	{
		fa[b]=a;
		siz[a]+=siz[b];
		rec[a].insert(rec[a].end(),rec[b].begin(),rec[b].end());
	}
	else{
		fa[a]=b;
		siz[b]+=siz[a];
		rec[b].insert(rec[b].end(),rec[a].begin(),rec[a].end());
	}
	return 1;
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	for(int i=0;i<26;i++)
	{
		siz[i]=1;
		fa[i]=i;
		rec[i].push_back(i);
	}
	string s,t;
	cin>>n>>s>>t;
	for(int i=0;i<n;i++)
	{
		Merge(s[i]-'a',t[i]-'a');
	}
	int ans=0;
	bool vis[maxn]={0};
	for(int i=0;i<26;i++)
	{
		int now=findfa(i);
		if(!vis[now])
		{
			vis[now]=1;
			ans+=siz[now]-1;
		}
	}
	cout<<ans<<endl;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<26;i++)
	{
		int now=findfa(i);
		if(siz[now]>1&&i!=now)
		{
			cout<<(char)('a'+i)<<' '<<(char)('a'+now)<<endl;
		}
	}
	return 0;
}


