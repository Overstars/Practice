//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
//#define ff first
//#define ss second
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
typedef pair<double,double> P;
const double eps=1e-8;
P get(const P &a,const P &b,const P&c)
{
	double X, Y;
	X = ((a.first * a.first - b.first * b.first + a.second * a.second - b.second * b.second) * (a.second - c.second) -
       (a.first * a.first - c.first * c.first + a.second * a.second - c.second * c.second) * (a.second - b.second)) /
      (2 * (a.second - c.second) * (a.first - b.first) - 2 * (a.second - b.second) * (a.first - c.first));
	Y = ((a.first * a.first - b.first * b.first + a.second * a.second - b.second * b.second) * (a.first - c.first) -
       (a.first * a.first - c.first * c.first + a.second * a.second - c.second * c.second) * (a.first - b.first)) /
      (2 * (a.second - b.second) * (a.first - c.first) - 2 * (a.second - c.second) * (a.first - b.first));
	return make_pair(X,Y);
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	P z({0,0});
	vector<P>a(n),cent;
	for(auto &x:a)
		cin>>x.first>>x.second;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if((double)abs(a[i].first*a[j].second-a[i].second*a[j].first)>eps)//不在一条线上
			cent.push_back(get(a[i],a[j],z));
		}
	sort(cent.begin(),cent.end());
	int ans,mul=0;
	for(int i=0,cnt=0;i<cent.size();i++)
	{
		cnt++;
		if(abs(cent[i].first-cent[i+1].first)>eps||abs(cent[i].second-cent[i+1].second)>eps)
		{
			mul=max(mul,cnt);
			cnt=0;
		}
	}
	for(ans=1;ans<=n;ans++)
		if(ans*(ans-1)==2*mul)
			break;
	cout<<ans<<endl;
	return 0;
}


