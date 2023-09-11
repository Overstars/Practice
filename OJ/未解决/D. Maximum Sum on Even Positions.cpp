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
ll a[maxn],dp[maxn],len[maxn],suf[maxn],odd[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		suf[n+1]=odd[n+1]=odd[n+2]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			suf[i]=len[i]=dp[i]=0;
		}
		for(int i=n;i>=1;i--)
		{
			suf[i]=suf[i+1]+a[i];//后缀和
			if(i&1)//奇数位后缀和
				odd[i]=odd[i+1]+a[i];
			else
				odd[i]=odd[i+1];//
		}//当某一段长度为偶数,且偶数位和>奇数位和,对调
		ll sub1=0,sub2=0,len1=0,len2=0;
		for(int i=n;i>=1;i--)
		{//当n为偶数时
			if(i&1)
				sub1+=a[i],sub2-=a[i];
			else
				sub1-=a[i],sub2+=a[i];
			len1++,len2++;
			if(sub1>0)//奇数位较大,无必要反转
				sub1=len1=0;
			if(sub2<0)//偶数位较小,无必要反转
				sub2=len2=0;
			if(i&1&&len1%2==0)
			{
//				dp[i]=
				len[i]=len1;
			}
			if(i%2==0)
			{
//				dp[i]=
				len[i]=len2;
			}
		}
		printf("suf:");
		for(int i=1;i<=n;i++)
			printf("%lld%c",suf[i],(i==n)?'\n':' ');
		printf("odd:");
		for(int i=1;i<=n;i++)
			printf("%lld%c",odd[i],(i==n)?'\n':' ');
		printf("len:");
		for(int i=1;i<=n;i++)
			printf("%lld%c",len[i],(i==n)?'\n':' ');
		ll ans=odd[1],pre=0;
		for(int i=1;i<=n;i++)
		{
			ll l=len[i];
			ans=max(ans,pre+(suf[i]-suf[i+l])-(odd[i]-odd[i+l])+odd[i+l]);
			if(i&1)
				pre+=a[i];
			printf("%d:l=%lld,now=%lld\n",i,l,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}


