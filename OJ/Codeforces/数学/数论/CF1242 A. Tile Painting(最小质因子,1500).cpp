#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n;
	vector<ll>ans;
	cin>>n;
	for(ll i=2;i*i<=n;i++)
	{//若n存在两个质因子p,q,则一定有一对位置
		if(n%i==0)
		{
			ans.push_back(i);
			while(n%i==0)
				n/=i;
		}
	}
	if(n>1)
		ans.push_back(n);
	if(ans.size()==1)//寻找一个最小的整数x,x^k=n,x即为答案
		cout<<ans[0]<<endl;
	else
		cout<<1<<endl;
	return 0;
}


