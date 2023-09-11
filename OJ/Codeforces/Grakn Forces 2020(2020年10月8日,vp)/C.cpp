//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
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
using ld=long double;
ld a[maxn];
int n,len;
bool check(ld time)
{
	ld d1=0,d2=0,t1=0,t2=0;
	int spd=1;
	for(int i=1;i<=n+1;i++)
	{
		if((a[i]-a[i-1])/spd+t1>time)
		{
			d1+=(time-t1)*spd;
			break;
		}
		else{
			d1+=a[i]-a[i-1];
			t1+=(a[i]-a[i-1])/spd;
			spd++;
		}
	}
	spd=1;
	for(int i=n;i>=0;i--)
	{
		if((a[i+1]-a[i])/spd+t2>time)
		{
			d2+=(time-t2)*spd;
			break;
		}
		else{
			d2+=a[i+1]-a[i];
			t2+=(a[i+1]-a[i])/spd;
			spd++;
		}
	}
//	cout<<"tim="<<time<<endl;
//	cout<<"d1="<<d1<<",d2="<<d2<<endl;
	return d1+d2>=(ld)len;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>len;//[0,len]
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ld ans=len,l=0,r=len;
		a[n+1]=len;
		while(abs(r-l)>eps)
		{
			ld mid=(l+r)/2;
			if(check(mid))
			{
				r=mid;
				ans=min(ans,mid);
//				cout<<"mid="<<mid<<endl;
			}
			else
				l=mid;
		}
		cout<<setiosflags(ios::fixed)<<setprecision(9)<<ans<<endl;
	}
	return 0;
}


