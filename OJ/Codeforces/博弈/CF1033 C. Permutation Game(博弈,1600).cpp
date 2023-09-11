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
bool vis[maxn],ans[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	vector<int>rec;
	for(int i=1;i<=n;i++)
		rec.push_back(i);
	sort(rec.begin(),rec.end(),[](int &x,int &y){
			return a[x]>a[y];
		});
	for(int &x:rec)
	{
		bool ok=0;
		int step=a[x];
		for(int i=x-x/step*step;i<=n;i+=step)
			if(vis[i]&&!ans[i])//转移到必败态
			{
				ok=1;
//				printf("%d->%d,val=%d,win\n",i,x,step);
				break;
			}
		ans[x]=ok;
		vis[x]=1;
	}
	for(int i=1;i<=n;i++)
		cout<<(ans[i]?"A":"B");
	return 0;
}


