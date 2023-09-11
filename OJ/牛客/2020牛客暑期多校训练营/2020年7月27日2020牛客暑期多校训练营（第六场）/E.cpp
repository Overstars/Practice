//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k;
//	for(int i=1;i<=100;i++)
//	{
////		printf("%d:%d\n",i,i*(i+1)/2%i);
//		bool ok=0;
//		int sum=i*(i+1)/2;
//		for(int j=2;j<=2*i-1;j++)
//		{
//			if((sum-j)%i==i/2)
//			{
//				printf("%d is %d-%d\n",i,sum,j);
////				break;
//			}
//		}
//		for(int j=1;j<=i;j++)
//		{
//			if((i*(i+1)/2-j)%i==i/2)
//			{
//				ok=1;
////				printf("%d is %d\n",i,j);
//				break;
//			}
//		}
//		printf("%d:%s\n",i,(ok)?"YES":"NO");
//	}
	cin>>n>>k;
	if(n&1)//sum一定被n整除,k=0时也无解
	{
		if(k>0)
			cout<<-1<<endl;
		else{
			cout<<n<<' ';
			for(int i=n/2;i>=1;i--)
				cout<<i<<' '<<n-i<<' ';
		}
	}
	else{
		if(k!=n/2)
			return cout<<-1<<endl,0;
		cout<<n<<' '<<n/2<<' ';
		for(int i=1;i<=n/2-1;i++)
			cout<<i<<' '<<n-i<<' ';
	}
	return 0;
}


