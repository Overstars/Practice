//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,a[4];
	cin>>n>>m;
	for(int i=0;i<4;i++)
		cin>>a[i];
	if(m<n+1||n<=4)
		cout<<-1<<endl;
	else{
		cout<<a[0]<<' '<<a[2]<<' ';
		for(int i=1;i<=n;i++)
			if(i!=a[0]&&i!=a[1]&&i!=a[2]&&i!=a[3])
				cout<<i<<' ';
		cout<<a[3]<<' '<<a[1]<<endl;
		cout<<a[2]<<' '<<a[0]<<' ';
		for(int i=1;i<=n;i++)
			if(i!=a[0]&&i!=a[1]&&i!=a[2]&&i!=a[3])
				cout<<i<<' ';
		cout<<a[1]<<' '<<a[3]<<endl;
	}
	return 0;
}


