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
char s[maxn];
int n;
ll dfs(int l,int r,int tim)
{
	char st='a'+tim-1;
	if(l==r)
		return s[l]!=st;
	int mid=(l+r)>>1,c1=0,c2=0;
	for(int i=l;i<=mid;i++)
		if(s[i]!=st)
			c1++;
	for(int i=mid+1;i<=r;i++)
		if(s[i]!=st)
			c2++;
	return min(c1+dfs(mid+1,r,tim+1),c2+dfs(l,mid,tim+1));
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>s+1;
		cout<<dfs(1,n,1)<<endl;
	}
	return 0;
}


