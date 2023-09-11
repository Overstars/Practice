//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
vector<pii>a;
int mp[10];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,x,y;
	cin>>n;
	for(int i=1;i<=9;i++)
	{
		cin>>x;
		a.push_back(pii(x,i));
		mp[i]=x;
	}
	sort(a.begin(),a.end(),[](pii &x,pii &y){
			if(x.ff==y.ff)
				return x.ss>y.ss;
			return x.ff<y.ff;
		});
	int len=n/a[0].ff;
	int ret=n%a[0].ff;
	if(len==0)
		return cout<<-1<<endl,0;
	list<int> ans;
	for(int i=1;i<=len;i++)
	{
		int now=a[0].ss;
		for(int j=9;j>=1;j--)
		{
			if(mp[now]+ret>=mp[j])
			{
				ret-=mp[j]-mp[now];
				now=j;
				break;
			}
		}
		cout<<now;
	}
	return 0;
}
/*
 *2020年12月26日16点22分
 *同权值取最大,位数更多
 *可能出现的问题是,
 *答案的位数一定与权值最小的相同
*/

