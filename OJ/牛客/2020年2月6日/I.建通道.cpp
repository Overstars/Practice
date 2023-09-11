#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG
ll ans=0,val[maxn],cnt[maxn],odd=0;
map<ll,int>mp;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>val[i];
		for(int j=0;j<32;j++)
		{
			if((val[i]>>j)&1)//第j位为1
				cnt[j]++;
		}
	}
	for(int i=0;i<32;i++)//
	{

	}
	return 0;
}


