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
		int c0=0,c1=0,c2=0,ok=0;
		for(int i=0;i*3<=n;i++)
		{
			for(int j=0;i*3+j*5<=n;j++)
			{
				for(int k=0;i*3+j*5+k*7<=n;k++)
				{
					if(i*3+j*5+k*7==n)
					{
						ok=1;
						c0=i,c1=j,c2=k;
						goto label;
					}
				}
			}
		}
		label:
		if(!ok)
			cout<<-1<<endl;
		else
			cout<<c0<<' '<<c1<<' '<<c2<<endl;
	}
	return 0;
}


