//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
char s[maxn];
int cnt[maxn][3];
signed main(int argc, char const *argv[])
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
		cin>>s+1;
		int res=0,n=strlen(s+1);
		for(int i=1;i<=n;i++)
			cnt[i][0]=cnt[i][1]=cnt[i][2]=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='*')
				cnt[i][0]++;
			else if(s[i]=='(')
				cnt[i][1]++;
			else
				cnt[i][2]++;
			for(int j=0;j<3;j++)
				cnt[i][j]+=cnt[i-1][j];
		}
		bool ok=1;
		for(int i=1,l=0,r=0;i<=n;i++)
		{
			if(cnt[i][0]+cnt[i][1]<cnt[i][2]||cnt[n][0]-cnt[i-1][0]+cnt[n][2]-cnt[i-1][0]<cnt[n][1]-cnt[i-1][1])
				ok=0;
			if(s[i]=='*')
				res++;
		}
	}
	return 0;
}


