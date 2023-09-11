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
int a[maxn],pre[maxn];
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,p;
	cin>>t;
	while(t--)
	{
		cin>>n>>p;
		for(int i=1;i<=n;i++)
			cin>>a[i],a[i]%=p;
		map<int,int>mp;
		int ans=0;
		for(int i=1,ind=0;i<=n;i++)
		{
			pre[i]=(pre[i-1]+a[i])%p;
			int pp=mp[pre[i]];
			if(pp>=ind&&!(pp==0&&pre[i]!=0))
			{
				ans++;
				ind=i;//取走[pre+1,i]
			}
			mp[pre[i]]=i;
//			printf("%d:ans=%d\n",i,ans);
//			printf("pre[%d]:%d,mp:%d ",i,pre[i],mp[pre[i]]);
//			mp[pre[i]]++;
//			ans=max(ans,mp[pre[i]]-1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
3 5
4 3 2
ans=1
2
2 6
1 1
6 4
2 3 1 4 4 4
ans=0,4.前缀和2,1,2,2,2,2
2
5 5
1 2 3 7 5
6 5
1 5 1 5 1 5
ans=2,3,取模后前缀和1 3 1 3 3
*/

