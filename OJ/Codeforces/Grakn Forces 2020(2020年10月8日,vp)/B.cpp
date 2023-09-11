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
int a[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		set<int>st;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			st.insert(a[i]);
		}
		if(st.size()>1&&k==1)
			cout<<-1<<endl;
		else{
			int ans=1,cnt=st.size()-k;
			if(cnt>0)
			{
				if(k>1)
					ans+=cnt/(k-1)+(cnt%(k-1)?1:0);
				else
					ans+=cnt;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
 *非递减的非负数组a
 *你找到m个长度为n的数组b1~bm
 *每个b数组不同数目最多k个
*/

