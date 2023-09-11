//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
int cnt[maxn],ok[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,a,ans=INT_MAX;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		int pre=0;//记录前缀次数
		while(a)
		{
			int c1=0;
			while(a%2==0)//记录被2整除的次数
				a>>=1,c1++;//tmp再从这头倒车回去
			for(int tmp=a,c2=0;tmp<maxn;tmp<<=1,c2++)
			{
				ok[tmp]++;//可达到
				cnt[tmp]+=pre+abs(c2-c1);
			}
			pre+=c1+1;
			a>>=1;
		}
	}
	for(int i=1;i<maxn;i++)
	{
		if(ok[i]==n)
			ans=min(ans,cnt[i]);
	}
	cout<<ans<<endl;
	return 0;
}


