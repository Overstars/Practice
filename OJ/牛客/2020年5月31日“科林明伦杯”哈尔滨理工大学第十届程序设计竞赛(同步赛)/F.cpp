#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
ull fib[maxn]={1,1,2,3,5},sum[maxn]={1,2,4,7,12};
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int lim=0;
	ull pre=0;
	for(int i=2;sum[i-1]<=18446744073709551615;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		sum[i]=sum[i-1]+fib[i];
		if(sum[i]<=pre)
			break;
		pre=sum[i];
		lim=i;
//		printf("sum[%d]=%llu\n",i,sum[i]);
	}
	ull t,a;
	cin>>t;
	while(t--)
	{
		cin>>a;
		ull *p=lower_bound(sum,sum+lim,a);
		if(*p>a)
			cout<<p-sum<<endl;
		else
			cout<<p-sum+1<<endl;
	}
	return 0;
}


