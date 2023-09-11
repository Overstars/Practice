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
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,k;
	string s;
	set<string>TAT;
	queue<string>QAQ;
	cin>>n>>k>>s;
	QAQ.push(s);
	TAT.insert(s);
	ll ans=0;
	while(!QAQ.empty())
	{
		string now=QAQ.front(),nex;
		QAQ.pop();
		if(TAT.size()>=k)
			break;
		for(int i=0;i<now.length();i++)
		{
			nex=now.substr(0,i)+now.substr(i+1,now.length()-i);
			if(TAT.count(nex)==0)
			{
				TAT.insert(nex);
				ans+=n-nex.length();
//				cout<<"nex="<<nex<<endl;
				if(TAT.size()>=k)
					break;
				QAQ.push(nex);
			}
		}
	}
	cout<<(TAT.size()<k?-1:ans)<<endl;
	return 0;
}
/*
 *没想出来dp的解法,瞄了眼题解,原来简单版本可以暴力
*/
