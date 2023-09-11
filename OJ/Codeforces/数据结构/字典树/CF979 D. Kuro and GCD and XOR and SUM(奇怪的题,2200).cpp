//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=1e5+10,inf=0x3f3f3f3f,mod=1000000007;
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
class Trie01
{
public:
	static const int maxm=2,start=18;//字符范围
	int trie[maxn<<7][maxm],path[maxn][maxm],isw[maxn],siz;//节点数siz
	int lazy[36],mi[maxn<<7];
	void init()
	{
		siz=maxn+1;
//		memset(lazy,0,sizeof(lazy));
//		memset(path,0,sizeof(path));
		memset(trie[0],0,sizeof(trie[0]));
		memset(mi,inf,sizeof(mi));
//		memset(isw,0,sizeof(isw));
	}
	void insert(const int &key,int rt)
	{//插入一个key
		mi[rt]=min(mi[rt],key);
		for(int i=start;i>=0;i--)
		{
			int id=(key>>i)&1;
			if(!trie[rt][id])
			{
//				memset(trie[siz],0,sizeof(trie[siz]));
				trie[rt][id]=siz++;//添加新节点
			}
//			path[rt][id]++;//子节点多少个
			rt = trie[rt][id];//向下
			mi[rt]=min(mi[rt],key);
		}
//		isw[rt]++;
	}
	int qmax(const int &key,int rt,int lim)
	{//查询异或最大
		if(mi[rt]>lim)//子树最小值>lim
			return -1;
		int ret=0;
		bool ok=0;
		for(int i=start;i>=0;i--)
		{
			int id=!((key>>i)&1),oth=(lim>>i)&1;//最好是不同的
			int lc=trie[rt][id],rc=trie[rt][!id];
			if(mi[lc]>lim&&mi[rc]<=lim)
				id^=1;
			else if(mi[lc]>lim&&mi[rc]>lim)
				return -1;
			rt=trie[rt][id];//向下
			ret=ret*2+id;
		}
		return ret;
	}
} tt;
vector<int>f[maxn];//f[i]存放i的所有因数
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int q,op,x,k,s;
	for(int i=1;i<maxn;i++)
		for(int j=i;j<maxn;j+=i)
			f[j].push_back(i);
	unordered_map<int,bool>vis;
	tt.init();
	cin>>q;
	while(q--)
	{
		cin>>op>>x;
		if(op==1)
		{//将x加入集合
			if(vis[x])
				continue;
			vis[x]=1;//把x插到所有除数i上
			for(auto &i:f[x])//根结点编号为i
				tt.insert(x,i);
		}
		else{
			cin>>k>>s;//在k树上找到val<=s-x的异或最大值
			if(s-x<0||x%k)//k不能整除x
			{
				cout<<-1<<endl;
				continue;
			}
			cout<<tt.qmax(x,k,s-x)<<endl;
		}
	}
	return 0;
}
/*
 * 2021-05-09-20.56.51
 * 操作2寻找的val满足以下条件
 * val<=s-x
 * k|gcd(val,x)
 * val ^ x尽量大
 * 注意要维护子树上最小值,因为直接for最终得到的异或最大值不一定能满足<=lim
 * lim = 100, x=110
 * 会搜索到 101上去,超出lim
 * 但答案在很久前的另一个子树上
*/

