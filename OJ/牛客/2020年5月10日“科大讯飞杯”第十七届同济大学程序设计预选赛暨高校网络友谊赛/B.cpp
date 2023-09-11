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
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	double ans=0;
	string s;
	cin>>s;
	bool fix=1,flag=0;
	ll a=0,x=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='+')
		{
//			printf("a=%lld,x=%lld\n",a,x);
			if(fix)
				ans+=a;
			else{
//				if(a*(x+1)%2)
//					flag=1;
				ans+=(double)a*(x+1)/2;
			}
//			printf("ans=%f\n",ans);
			a=x=0;
			fix=1;
		}
		else if(s[i]=='d')
		{//是一个投掷
			fix=0;
		}
		else{
			if(fix)
				a=a*10+(ll)(s[i]-'0');
			else
				x=x*10+(ll)(s[i]-'0');
		}
	}
	if(fix)
		ans+=a;
	else{
		if(a*(x+1)%2)
			flag=1;
		ans+=(double)a*(x+1)/2;
	}
	if((ll)ans!=ans)
		cout<<setiosflags(ios::fixed)<<setprecision(1)<<ans<<endl;
	else
		cout<<(ll)ans<<endl;
	return 0;
}


