//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
int ans[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<bool>vis(n,false);
		int now=1,ok=1;
		for(int i=1;i<n;i++)
		{
			ans[i]=now;
			vis[now]=1;
			if(vis[now*2%n]&&vis[now*3%n]&&i!=n-1)
			{
				ok=0;
				break;
//				printf("now=%d\n",now);
			}
			if(!vis[now*2%n])
				now=now*2%n;
			else
				now=now*3%n;
		}
		if(!ok)
		{
			cout<<-1<<endl;
			continue;
		}
		for(int i=1;i<n;i++)
			cout<<ans[i]<<' ';
		cout<<endl;
	}
	return 0;
}
/*
999
47
*/

