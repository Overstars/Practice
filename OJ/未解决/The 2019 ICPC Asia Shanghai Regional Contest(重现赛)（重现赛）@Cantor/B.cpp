//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
class Trie
{
public:
	static const int maxm=26;//字符范围
	int trie[maxn][maxm],isw[maxn],path[maxn],siz;//节点数siz
	void init()
	{
		siz=1;
		memset(trie[0],0,sizeof(trie[0]));
		memset(isw,0,sizeof(isw));
		memset(path,0,sizeof(path));
	}
	inline int mp(const char &ch)
	{//[a,z]到[0,25]的映射
		return (int)(ch-'0');
	}
	bool insert(string &key)
	{//插入一个key
		int rt=0;
		for(char &ch:key)
		{
			int id=mp(ch);
			if(!trie[rt][id])
			{//
				memset(trie[siz],0,sizeof(trie[siz]));
				trie[rt][id]=siz++;
			}
			path[rt]++;
			rt=trie[rt][id];
			if(isw[rt])
				return 0;
		}
		if(isw[rt]||path[rt])
			return 0;
		path[rt]++;
		isw[rt]++;
		return 1;
	}
	int query(string &key)
	{//查询key的数量
		int rt=0;
		for(char &ch:key)
		{
			int id=mp(ch);
			if(!trie[rt][id])//不存在
				return 0;
			rt=trie[rt][id];
		}
		return isw[rt];
	}
} tr;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int T,n;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		string s;
		vector<string> rec;
		cin>>n;
		tr.init();
		bool ok=1;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			ok&=tr.insert(s);
		}
		cout<<"Case #"<<t<<": ";
		cout<<(ok?"Yes":"No")<<endl;
	}
	return 0;
}
/*
5
4
123
123
12
1234
2
123
321
3
123
233
23
*/
/*
 * 2021-04-28-15.26.18
*/

