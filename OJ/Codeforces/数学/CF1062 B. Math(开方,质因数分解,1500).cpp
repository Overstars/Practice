//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
inline bool isp(ll x)
{
	ll s=sqrt(x);
	return s*s==x;
}
void attempt()
{
	ll n,cnt=0;
	cin>>n;
	while(1)
	{
		while(isp(n))
		{
			cnt++;
			n=sqrt(n);
		}
		bool ok=1;
		for(ll i=2;i<n;i++)
		{
			if(isp(n*i))
			{
				ok=0;
				n=i*n;
				cnt++;
				break;
			}
		}
		if(ok)
			break;
	}
	cout<<n<<' '<<cnt<<endl;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n,ans=1,ans2=0;
	vector<ll>fac,rec;
	cin>>n;
	bool ok=1;
	ll tmp=n;
	for(ll i=2;i*i<=n;i++)
	{
		if(tmp%i==0)
		{
			fac.push_back(i);
			ll now=0,cnt=0;
			while(tmp%i==0)
				tmp/=i,cnt++;
			rec.push_back(cnt);
//			if(cnt&(cnt-1))
//				ok=0;//存在不为2的幂的数
		}
	}
	if(tmp>1)
		fac.push_back(tmp),rec.push_back(1);
	sort(rec.begin(),rec.end());
	rec.erase(unique(rec.begin(),rec.end()),rec.end());//去重
	for(ll &x:rec)//每个的数量
	{
		ll now=0;
		if(x&(x-1))//不为2的幂
			now=(ll)log2(x)+2;//一步变为二的幂,多了一步开方
		else if(rec.size()==1)
			now=(int)log2(x);
		else
			now=(int)log2(x)+1;
//		printf("f:%lld x:%lld now:%lld\n",i,x,now);
		ans2=max(ans2,now);
	}
	for(ll &x:fac)
		ans*=x;
	cout<<ans<<' '<<ans2<<endl;
	return 0;
}


