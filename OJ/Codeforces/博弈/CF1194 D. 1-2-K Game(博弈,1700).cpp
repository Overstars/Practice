//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
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
int n,k,SG[maxn]={0,1,2};
bool vis[maxn];
int sg(int x)
{
	if(x==0)//上一个状态1/2/k
		return 0;
	else if(x==1||x==2)
		return x;
	else if(vis[x])
		return SG[x];
	int mp[105]={0};
//	memset(mp,0,sizeof(mp));
	mp[sg(x-1)]=1,mp[sg(x-2)]=1;
	if(x>=k)
		mp[sg(x-k)]=1;
	vis[x]=1;
	for(int i=0;i<maxn;i++)
		if(mp[i]==0)
			return SG[x]=i;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t=1;
//	cin>>t;
	while(t--)
	{
//		cin>>n>>k;
		printf("k=  ");
		int lim=30;
		for(int i=3;i<=lim;i++)
			printf("%2d%c",i,(i==lim?'\n':' '));
		for(int i=0;i<=lim;i++)
		{
			if(i>=3)
				printf("n=%2d",i);
			for(k=3;k<=i;k++)
			{
				memset(vis,0,sizeof(vis));
				printf("%2d%c",sg(i),(k==i?'\n':' '));
			}
		}
		bool ok=0;
		if((n%3&&k%3)||(k>n&&n%3))//k过大就是巴什博弈,与3无关先手必胜
			ok=1;
		if(n>k&&k%3==0&&(n-1)%3==0)
			ok=0;
		else if(n%3==0)
			ok=1;
		cout<<(ok?"Alice":"Bob")<<endl;
	}
	return 0;
}
/*
 *如果不考虑k,当n%3为0时必败
 *打SG表,发现n==k时先手必胜
 *k=3使得原本的n=3必败态/转为了必胜态
 *
 */

