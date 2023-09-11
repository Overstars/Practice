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
	int t,n,T;
	cin>>t;
	while(t--)
	{
		cin>>n>>T;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		map<int,int> isa;
		for(int i=1;i<=n;i++)
		{
			if(isa[T-a[i]]==1)//
			{
				cout<<"0 ";
				isa[a[i]]=2;//分到b组
			}
			else{
				cout<<"1 ";
				isa[a[i]]=1;
			}
		}
		cout<<endl;
	}
	return 0;
}
/*
999
5 4
2 2 2 2 2
*/
/*
 *一个数组如果存在两个数和为T,则不幸+1
*/

