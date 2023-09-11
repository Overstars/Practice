//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=3e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
int a[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=1,r=0,cnt=0,al=0,ar=0;//统计[l,r]内0的个数
	for(;r<n;l++)
	{
		for(;cnt<=k&&r<n;r++)
			if(a[r+1]==0)
			{
				if(cnt<k)
					cnt++;
				else
					break;
			}
//		printf("l=%d,r=%d\n",l,r);
		if(r-l+1>ans)
		{
			ans=r-l+1;
			al=l;ar=r;
		}
		if(a[l]==0)
			cnt--;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		if(al<=i&&i<=ar)
			cout<<1<<' ';
		else
			cout<<a[i]<<' ';
	return 0;
}


