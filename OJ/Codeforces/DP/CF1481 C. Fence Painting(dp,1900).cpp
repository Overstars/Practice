
//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
int a[maxn],b[maxn],c[maxn],ans[maxn];
set<int>col[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			col[i].clear();
		for(int i=1;i<=n;i++)//初始颜色
			cin>>a[i];
		for(int i=1;i<=n;i++)//希望涂的颜色
			cin>>b[i];
		for(int i=1;i<=m;i++)
			cin>>c[i];
		int ed=0,cnt=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i])//必须
			{
				col[b[i]].insert(i);
				cnt++;
			}
		bool ok=0;
		if(!col[c[m]].empty())
		{
			ed=*col[c[m]].begin();
			col[c[m]].erase(ed);
			cnt--;
		}
		if(!ed)
		{
			for(int i=1;i<=n;i++)
				if(b[i]==c[m])
					ed=i;
		}
		if(ed)
		{
//			int ed=*col[c[m]].begin();
			ans[m]=ed;
			for(int i=1;i<m;i++)
			{
				if(col[c[i]].empty())
					ans[i]=ed;
				else{//还有地方
					int now=*col[c[i]].begin();
					col[c[i]].erase(now);
					cnt--;
//					a[now]=c[i];
					ans[i]=now;
				}
			}
			if(cnt==0)
				ok=1;
//			a[ed]=c[m];
//			bool flag=0;
//			for(int i=1;i<=n;i++)
//				if(!col[c[i]].empty())
//					flag=1;
//			if(!flag)
//				ok=1;
//			for(int i=1;i<=n;i++)
//				if(a[i]!=b[i])
//					ok=0;
		}
		cout<<(ok?"YES":"NO")<<endl;
		if(ok)
		{
			for(int i=1;i<=m;i++)
				cout<<ans[i]<<' ';
			cout<<endl;
		}
	}
	return 0;
}
/*
 * 2021-04-11-14.53.31
 * 题意	总感觉眼熟...
 * 求最后一个木匠涂的颜色是否在b中出现
 * 则所有其他无用颜色都可以涂在该木板上
 * 否则贪心涂所有对应未涂的即可
 * 很奇怪为什么使用cnt就能过
*/


