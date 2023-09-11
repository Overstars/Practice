#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG
int s(int x)
{
	while(x>=10)
	{
		int now=0;
		for(;x;x/=10)
		{
			now+=x%10;
		}
		x=now;
	}
	return x;
}
int ans[maxn],cnt[10];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
//	for(int i=1;i<=100;i++)
//	{
//		ans[i]=s(i);
//		int no=++cnt[ans[i]];
//		printf("s(%d)=%d,no=%d\n",i,ans[i],no);
//	}
	ll t,k,x;
	cin>>t;
	while(t--)
	{
		cin>>k>>x;
		cout<<x+9*(k-1)<<endl;
	}
	return 0;
}


