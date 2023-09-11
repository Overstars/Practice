//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=3e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
	static const int maxm=2,start=30;//字符范围
	int trie[maxn][maxm],path[maxn][maxm],isw[maxn],siz;//节点数siz
	int lazy[36];
	void init()
	{
		siz=1;
		memset(lazy,0,sizeof(lazy));
		memset(path,0,sizeof(path));
		memset(trie[0],0,sizeof(trie[0]));
		memset(isw,0,sizeof(isw));
	}
	void insert(const int &key)
	{//插入一个key
		int rt=0;
		for(int i=start;i>=0;i--)
		{
			int id=(key>>i)&1;
			if(!trie[rt][id])
			{
				memset(trie[siz],0,sizeof(trie[siz]));
				trie[rt][id]=siz++;//添加新节点
			}
			path[rt][id]++;//子节点多少个
			rt = trie[rt][id];//向下
		}
		isw[rt]++;
	}
	int qmin(const int &key)
	{//查询异或最小值(考虑xor操作)
		int rt=0,ret=0;
		for(int i=start;i>=0;i--)
		{
			int id=(key>>i)&1,nex=0;//最好是相同的,异或为0,答案更小
			id^=lazy[i];//看这一位有没有被反转
			if(path[rt][id]==0)//这种情况莫得了
			{
				id^=1;//换较差的那种
				nex=1;//该位的贡献
			}
			ret=(ret<<1)+nex;
//			path[rt][id]--;//该边数量减1
			rt=trie[rt][id];//向下
		}
		return ret^key;
	}
	void Xor(const int &key)
	{//所有值全部异或
		for(int i=start;i>=0;i--)
		{//如果该边被对调,标记在其父结点上
			int id=(key>>i)&1;
			lazy[i]^=id;//1反转,该深度所有点都被标记
		}
	}
	int mex()
	{//查询不在键值集合内的最小值
		int rt=0,ret=0;//
		for(int i=start;i>=0;i--)
		{//0边子树非满走0边
			int id=lazy[i],nex=0;//是否被对调,id那边是现在的0
			if(path[rt][id]>=(1<<i))//最优的那边满了,叶子点数=2^i
			{
				id^=1;//走id的另一边
				nex=1;//该位的贡献为1
			}
//			printf("i= %d,rt = %d, nex=%d, lc =%d,rc = %d,lazy=%d\n",i,rt,nex,path[rt][nex],path[rt][!nex],lazy[i]);
			ret=(ret<<1)+nex;
			if(!trie[rt][id])//这边的子树还没有点,都可以取最小的
			{
				ret<<=i;
				break;
			}
			rt=trie[rt][id];
		}
		return ret;
	}
} tt;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,key;
	cin>>n>>m;
	vector<int> f(n);
	for(auto &i:f)
		cin>>i;
	sort(f.begin(),f.end());
	f.erase(unique(f.begin(),f.end()),f.end());
	tt.init();
	for(auto &i:f)
	{
//		cout<<"insert "<<i<<endl;
		tt.insert(i);
	}
	while(m--)
	{
		cin>>key;
		tt.Xor(key);
		cout<<tt.mex()<<endl;
	}
	return 0;
}
/*
 * 2021-05-02-10.49.26
 * 整体异或代表01字典树左右子树对调,自底向上
 * 如果异或key值该位为1,对该深度打一个标记
 * 否则如果递归反转的话,复杂度指数级的
 * 为查询mex,似乎要在字典树中递归计数,看节点是不是满的
*/

