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
double get(const pii &a,const pii &b)
{
	if(a.first==b.first)
		return 1e9+7;
	if(a.second==b.second)
		return 0;
	return (double)(b.second-a.second)/(b.first-a.first);
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,ans=0,cnt=0;
	vector<pii>v;
	map<double,int>mp;
	vector<int>rec;
	cin>>n;
	for(int i=0,a,b;i<n;i++)
	{
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			pii &a=v[i],&b=v[j];
			double k=get(a,b);
			if(mp.find(k)==mp.end())
			{
				mp[k]=cnt++;
				rec.push_back(0);
			}
			rec[mp[k]]++;
		}
	}
//	for(int i=0;i<cnt;i++)
//	{
//		for(int j=i+1;j<cnt;j++)
//			ans+=rec[i]*rec[j];
//	}
	cout<<cnt<<endl;
	return 0;
}


