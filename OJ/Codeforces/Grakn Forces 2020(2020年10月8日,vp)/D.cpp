//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
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
vector<int> need[maxn];//向上x步后还需need[x]
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,MAX=0;
	cin>>n>>m;
	vector<pii>a(n),b(m);
	for(pii &x:a)
		cin>>x.ff>>x.ss;
	for(pii &x:b)
		cin>>x.ff>>x.ss;
	for(pii &x:a)
	{
		for(pii &y:b)
		{
			MAX=max(MAX,y.ff-x.ff);
			if(y.ff-x.ff>=0)//向上走时需要向右走多少
				need[y.ff-x.ff].push_back(y.ss-x.ss+1);
		}
	}
	int ans=inf,now=0;
	for(int i=MAX+1;i>=0;i--)
	{//枚举向上行走的步数
		for(int &j:need[i])//统计全局向右走的步数
			now=max(now,j);
		ans=min(ans,i+now);
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *坐标系上有n个强盗和m个探照灯
 *你可以让所有强盗向右或向上
*/
/*
int ans1=0,ans2=0;
	for(pii &x:a)
	{
		int up=0,right=0;
		for(pii &y:b)
		{
			if(x.ff>y.ff||x.ss>y.ss)
				continue;
			if(y.ff-x.ff+1-up>=y.ss-x.ss+1-right)
				right=max(right,y.ss-x.ss+1);
			else
				up=max(up,y.ff-x.ff+1);
//			up=max(up,y.ff-x.ff+1);
//			right=max(right,y.ss-x.ss+1);
		}
		if(up<inf)
			ans1=max(ans1,up);
		if(right<inf)
			ans2=max(ans2,right);
	}
	if(ans1==inf||ans2==inf)
		return cout<<0<<endl,0;
	cout<<ans1+ans2<<endl;
//	cout<<min(ans1,ans2)<<endl;
*/
