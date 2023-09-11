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
		int c0=0,c1=0;
		vector<int>ans,v0,v1;
		for(int i=1,tmp;i<=n;i++)
		{
			cin>>tmp;
			if(tmp==1)
				c1++;
			else
				c0++;
//			if(tmp==1)
//			{
//				if(c1)
//					ans.push_back(1),c0=c1=0;
//				else
//					c1=1,c0=0;
//			}
//			else if(tmp==0)
//			{
//				if(c0)
//					ans.push_back(0),c0=c1=0;
//				else
//					c0=1,c1=0;
//			}
		}
		if(c1&1)
			c1--;
		cout<<max(c0,c1)<<endl;
		if(c0>=c1)
			for(int i=1;i<=c0;i++)
				cout<<0<<' ';
		else{
			for(int i=1;i<=c1;i++)
			{
				cout<<1<<' ';
			}
		}
		cout<<endl;
	}
	return 0;
}


