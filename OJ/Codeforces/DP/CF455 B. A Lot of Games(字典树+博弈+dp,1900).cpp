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
map<int,int> wtf;
class Trie
{
public:
	static const int maxm=26;//字符范围
	int trie[maxn][maxm],isw[maxn],siz;//节点数siz
	int dp[maxn];
	void init()
	{
		siz=1;
		memset(trie[0],0,sizeof(trie[0]));
		memset(isw,0,sizeof(isw));
	}
	inline int mp(const char &ch)
	{//[a,z]到[0,25]的映射
		return (int)(ch-'a');
	}
	void insert(string &key)
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
			rt=trie[rt][id];
		}
		isw[rt]++;
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
	int dfs(int rt)
	{
		map<int,int>cnt;
		for(int i=0;i<26;i++)
		{
			if(trie[rt][i])
			{
				cnt[dfs(trie[rt][i])]++;
			}
		}
//		if(rt==0)
//			wtf=cnt;
//		cerr<<"rt = "<<rt<<endl;
//		for(auto &i:cnt)
//			cerr<<"val = "<<i.ff<<", cnt = "<<i.ss<<endl;
		if(cnt.empty())//叶子节点
			return 1;//必胜态
		if(cnt.size()==1)
		{
			if(cnt.count(2))//只有必胜态
				return dp[rt]=1;//必败态
			else if(cnt.count(1))//只有必败态
				return dp[rt]=2;//必胜态
			else if(cnt.count(3))//下一步的人可以主动选择
				return dp[rt]=0;//被迫
			else
				return dp[rt]=3;//自己任选
		}
		if(cnt.count(0))//下一步存在被迫
			return dp[rt]=3;//自己可以主动选择
		else if(cnt.count(1)&&cnt.count(2))
			return dp[rt]=3;
		else if(cnt.count(1))
			return dp[rt]=2;//选择必胜
		else
			return dp[rt]=1;//选则必败
	}
} t;
signed main(signed argc, char const *argv[])
{
//	cout<<setiosflags(ios::fixed)<<setprecision(9)<<sqrt(1.5)<<endl;
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	t.init();
	int n,k;
	cin>>n>>k;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		t.insert(s);
	}
	t.dfs(0);
	bool ok=1;
//	if(wtf.count(3))
//		ok=1;
//	else if(wtf.count(1)&&wtf.count(2))//自由选择
//		ok=1;
//	else if(wtf.size()==1)
//	{
//		if(wtf.count(1)&&k%2==0)//只有必败态
//			ok=1;
//		else if(wtf.count(2)&&k%2==1)
//			ok=1;
//	}
//	cerr<<"t = "<<t.dp[0]<<endl;
	if(t.dp[0]==0||t.dp[0]==1||(t.dp[0]==2&&k%2==0))
		ok=0;
	cout<<(ok?"First":"Second")<<endl;
	return 0;
}
/*
 * 2021-04-26-10.55.16
 * 摸了一上午
 * k次和单独一局似乎可以分开处理
 * 看先手能不能自由选择让自己必胜/必败的方案
 * 先手若只能获胜,则k为偶数必败
 * 先手若必败,则一直必败
 * 若先手能自由选择,则先手必胜
 * k=1,选择胜
 * k=2,选择败,下一局自己仍先手必胜
 * k=3,败败胜
 * k=4,败败败胜
 * 一局内状态可以用字典树上树形dp判断
 * 叶子节点为必胜态10
 * 若儿子只有10,则自己为01(必败态)
 * 若儿子存在10和01,则自己为11(自由选择)
 * 若儿子只有11,则自己为00(被动选择)
 * 只要儿子存在00,则自己为11
*/

