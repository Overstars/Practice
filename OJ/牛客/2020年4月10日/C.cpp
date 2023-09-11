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
int fa[15],siz[15];
int findfa(int x)
{
	if(fa[x]!=x)
		fa[x]=findfa(fa[x]);
	return fa[x];
}
bool Merge(int x,int y)
{
	int a=findfa(x),b=findfa(y);
	if(a==b)
		return 0;
	if(a<b)
		fa[b]=a,siz[a]+=siz[b];
	else
		fa[a]=b,siz[b]+=siz[a];
	return 1;
}
ll POW(ll a,ll b,ll p)
{
	ll ans = 1;
	while(b){
		if(b&1)
			ans = (ans%p*a%p) % p;
		a = (a%p*a%p) % p;
		b >>= 1;
	}
	return ans%p;
}
ll C(ll n,ll m,ll p)
{
	if(m > n)return 0;
	if(m == n)return 1;
	if(m > n - m)m = n - m;
	ll a = 1, b = 1 ;
	for(ll i = 0 ; i < m ; i++){
		a = a * (n - i) % p;
		b = b * (i + 1) % p;
	}
	return a * POW(b,p-2,p) % p;
}
ll lucas(ll n,ll m,ll p=mod){//C(n,m)%p
	if(m == 0)
		return 1;
	return C(n%p,m%p,p)*lucas(n/p,m/p,p)%p;
}
ll A(ll n,ll m)
{
	ll ret=1;
	for(ll i=n-m+1;i<=n;i++)
		ret*=i;
	return ret;
}
bool vvis[1<<12];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	for(int i=1;i<=12;i++)
		fa[i]=i,siz[i]=1;
	ll a[4],m;
	for(int i=0;i<4;i++)
		cin>>a[i];
	cin>>m;
	bool vis[maxn]={0};
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		Merge(x,y);
	}
	vector<ll> vec;
	for(int i=1;i<=12;i++)
		if(!vis[findfa(i)])
			vec.push_back(siz[findfa(i)]),vis[findfa(i)]=1;
	sort(vec.begin(),vec.end());
	ll ans=0,tot=vec.size();
	//_builtin_popcount
	for(int i=0;i<=(1ll<<tot)-1;i++)
	{//枚举状态,选择集合中的元素
		ll s[5]={0};
		ll now1=0;//选中的集合总大小
		for(int tmp=1,cc=0;tmp<=i;tmp<<=1,cc++)
		{
			if(i&tmp)
				now1+=vec[cc];
		}
		for(int ii=0;ii<4;ii++)
		{
			if(now1==a[ii])
			{
				s[ii]=1;
				for(int j=0;j<=(1ll<<tot)-1;j++)
				{//枚举第二种颜色组合
					if(j&i)
						continue;
					ll now2=0;
					for(int tmp=1,cc=0;tmp<=j;tmp<<=1,cc++)
					{
						if(j&tmp)
							now2+=vec[cc];
					}
					for(int jj=0;jj<4;jj++)
					{
						if(!s[jj]&&now2==a[jj])
						{
							s[jj]=1;
							for(int k=0;k<=(1ll<<tot)-1;k++)
							{//第三层组合
								if(k&j||k&i)
									continue;
								ll now3=0;
								for(int tmp=1,cc=0;tmp<=k;tmp<<=1,cc++)
								{
									if(k&tmp)
										now3+=vec[cc];
								}
								for(int kk=0;kk<4;kk++)
								{
									if(!s[kk]&&now3==a[kk])
									{//now1,now2,now3,
										ans+=lucas(12,now1)*lucas(12-now1,now2)*lucas(12-now1-now2,now3);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}


