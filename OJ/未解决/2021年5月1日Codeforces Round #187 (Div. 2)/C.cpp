//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
int a[maxn];//原来的rating
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k;
	cin>>n>>k;
	set<int>st;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		st.insert(i);
	}
	vector<int>res;//保留
	int nown=n,p1=0,p2=0;
	for(int i=1;i<=n;i++)
	{
		int id=res.size()+1;//目前被考虑的排名
//		cerr<<"id = "<<id<<endl;
		if(id>1)
		{
			p2=a[i]*(nown-id)*(id-1);
			p1+=a[res[id-2]]*(id-2);//上一个
		}
//		cerr<<"d = "<<p1-p2<<endl;
//		for(int &i:res)
//			cerr<<i<<' ';
//		cout<<endl;
		if(p1-p2<k)//放弃
		{
			nown--;
			if(id>1)
				p1-=a[res[id-2]]*(id-2);
		}
		else{
			res.push_back(i);
		}
	}
	for(int &i:res)
	{
		st.erase(i);
//		cout<<i<<endl;
	}
//	cerr<<"ans = "<<endl;
	for(auto &i:st)
		cout<<i<<'\n';
	cout<<endl;
	return 0;
}
/*
 * 2021-05-01-15.20.38
*/

