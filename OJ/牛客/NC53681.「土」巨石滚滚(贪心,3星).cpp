#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
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
//struct cmp1
//{
//	bool operator()(const node &x,const node &y)
//	{
//		return x.a>y.a;
//	}
//};
//struct cmp2
//{
//	bool operator()(const node &x,const node &y)
//	{
//		return x.a+x.b<y.a+y.b;
//	}
//};
struct node
{
	int a,b;
	node(int a,int b):
		a(a),b(b){}
	bool operator <(const node &x)
	{
		if(b>a&&x.b>x.a)//结束都恢复,消耗小的先来
			return a<x.a;
		if(b>a)//否则选回复的
			return 1;
		if(x.b>x.a)
			return 0;
		return b>x.b;
	}
};
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m,a,b;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;//障碍个数,稳定性
		vector<node>vec;
//		priority_queue<node,vector<node>,cmp1>pos;
//		priority_queue<node,vector<node>,cmp2>neg;
		for(int i=1;i<=n;i++)
		{
			cin>>a>>b;
			vec.push_back(node(a,b));
//			if(b>=0)
//				pos.push(node(a,b));
//			else
//				neg.push(node(a,b));
		}
		sort(vec.begin(),vec.end());
		bool ok=1;
		for(auto &x:vec)
		{
			if(m<x.a)
			{
				ok=0;
				break;
			}
			m+=x.b-x.a;
		}
		cout<<(ok?"Yes":"No")<<endl;
	}
	return 0;
}


