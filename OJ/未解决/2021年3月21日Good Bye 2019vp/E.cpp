//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,x,y;
	cin>>n;
	vector<pii>rec(n);
	vector<int> st,st2;
	for(auto &i:rec)
	{
//		cin>>i.ff>>i.ss;
		cin>>x>>y;
		if(!((x&1)^(y&1)))
			st.push_back(i);
		else
			st2.push_back(i);
	}
	if(st.size()>st2.size())
	{
		cout<<st.size()<<endl;
		for(pii &i:st)
			cout<<i<<endl;
	}
	else{
		cout<<st2.size()<<endl;
		for(pii &i:st2)
			cout<<i<<endl;
	}
	return 0;
}
/*
 *感觉像n^2建图的2-SAT
*/

