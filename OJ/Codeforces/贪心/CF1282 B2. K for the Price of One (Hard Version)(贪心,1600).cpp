#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,p,k;
	cin>>t;
	while(t--)
	{//有p元,每k个物品可以支付其中最高那个带走
		cin>>n>>p>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		int ans=0,pre=0;
		for(int i=1;i<=k;i++)
		{//以i作为打包里最便宜的那个
			if(i)//前面的i-1个单独买下
				pre+=a[i-1];
			if(pre>p)
				break;
			int cnt=i-1,now=p-pre;
			for(int j=i+k-1;j<=n;j+=k)
			{//从i开始每k个打包买
				if(now>=a[j])
				{
					now-=a[j];
					cnt+=k;
				}
				else
					break;
			}
			ans=max(ans,cnt);
		}
		cout<<ans<<endl;
	}
	return 0;
}


