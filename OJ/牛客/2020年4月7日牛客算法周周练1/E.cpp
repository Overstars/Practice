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
ll qmod(ll a,ll b)  //快速幂
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
ll get(ll dig,ll num)
{
	ll ret=num;//的到指定位数的数字
	for(int i=1;i<dig;i++)
	{
		ret*=10;
		ret+=num;
	}
	return ret;
}
ll fun(ll x)
{//返回下一位幸运数字
	ll dig=0,tmp=x;
	bool low4=0,have=0;
	while(tmp>0)
	{
		dig++;
		if(tmp%10<4)
			low4=1;
		else if(tmp%10>4)
			have=1;
		tmp/=10;
	}
	ll a=get(dig,7),b=get(dig,4);//最大,最小
	if(x<=a)
	{
		if(have&&!low4)//不全是4,且没有比4小的数,有比4大的数
			return a;//返回全7
		if(x<=b)//
			return b;
		else{
			ll ret=0,tmp=x;
			for(int i=1;i<=dig;i++)//在范围之间
			{//由低到高得到x的第i位
				ll md=qmod(10,i);
				ll now=x%md;
				now/=md/10;
				if(x<=4)
					ret+=4/md/10;
				else{
					x+=md;//进一位
					ret+=7*md/10;
				}
				printf("x=%lld,%lld\n",x,ret);
			}
		}
	}
	return get(dig+1,4);
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	for(ll i=1;i<=100;i++)
		printf("%lld:%lld\n",i,fun(i));
	ll l,r;
	while(cin>>l>>r)
	{
		ll ans=0;
		while(l<=r)
		{
			ll nex=fun(l);
			if(nex>=r)
			{
				ans+=(r-l+1)*nex;
				printf("[%lld,%lld]=%lld,tot=%lld,ans=%lld\n",l,r,nex,(r-l+1)*nex,ans);
				break;
			}
			printf("[%lld,%lld]=%lld,tot=%lld\n",l,nex,nex,(nex-l+1)*nex);
			ans+=(nex-l+1)*nex;
			l=nex+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}

