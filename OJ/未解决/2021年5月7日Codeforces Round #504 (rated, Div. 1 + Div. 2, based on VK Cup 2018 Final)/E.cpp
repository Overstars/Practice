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
char ans[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	bool ok=1;
	string s1,s2;
	int nx=1,ny=1;
	for(int i=1;i<=n-1;i++)
	{//向(n,n)接近
		bool down=1;
		if(nx+1>n)
		{
			down=0;
		}
		else if(ny+1>n)
			down=1;
		else{//能向下走?
			cout<<"? "<<nx+1<<' '<<ny<<' '<<n<<' '<<n<<endl;
			cout.flush();
			cin>>s1;
//			cout<<"? "<<nx<<' '<<ny+1<<' '<<n<<' '<<n<<endl;
//			cout.flush();
//			cin>>s2;
			if(s1[0]=='N')
				down=0;
		}
		if(down)
		{//尽量向下
			nx++;
			ans[i]='D';
		}
		else{
			ny++;
			ans[i]='R';
		}
	}
	int mx=n,my=n;
	for(int i=n-1;i>=1;i--)
	{//还有3n+1次询问机会
		bool left=1;//尽量向左
		if(my-1<1)
		{
			left=0;
		}
		else if(mx-1<1)
			left=1;
		else{//能否向左?
			cout<<"? 1 1 "<<mx<<' '<<my-1<<endl;
			cout.flush();
			cin>>s1;
//			cout<<"? 1 1 "<<mx<<' '<<my-1<<endl;
//			cout.flush();
//			cin>>s2;
			if(s1[0]=='N')
				left=0;
		}
		if(left)
		{//向下,向(n,n)接近
			my--;
			ans[n-1+i]='R';
		}//尽量向
		else{
			mx--;
			ans[n-1+i]='D';
		}
	}
	cout<<"! ";
//	cout<<(ok?"YES":"NO")<<endl;
	if(ok)
		cout<<ans+1<<endl;
	cout.flush();
	return 0;
}
/*
 * 2021-05-07-14.50.18
 * n*n网格,bob只能向→或向
 +↓
 * 最多问4n个问题,且曼哈顿距离>=n-1
 * 找到一种方案从(1,1)到(n,n)
 * 如何从对角线上到达(n,n)
*/

