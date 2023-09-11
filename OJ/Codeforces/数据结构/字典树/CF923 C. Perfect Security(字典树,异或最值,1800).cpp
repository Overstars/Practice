//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int inf=0x3f3f3f3f,mod=1000000007;
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
const int maxn = 300005, M = 2;
int trie[maxn<<5][M],cnt[maxn<<5][M],isw[maxn],siz;
void init()//fail指向当前状态的最长后缀状态
{
	siz=1;
//	memset(trie[0],0,sizeof(trie[0]));
//	memset(isw,0,sizeof(isw));
}
void Insert(const int key)//rt传入0
{//trie插入模式串
	int rt=0;
	cnt[rt][0]++;//这位肯定是0的
	for(int i=30;i>=0;i--)//固定向下31位
	{
		int id = (key>>i)&1;
		if(!trie[rt][id])
		{
//			memset(trie[siz],0,sizeof(trie[siz]));
			trie[rt][id]=siz++;//添加新节点
		}
		cnt[rt][id]++;//子节点多少个
		rt = trie[rt][id];//向下
	}
//	isw[rt]++;
}
int query(int key)
{
	int rt=0,ret=0;
	cnt[rt][0]--;
	for(int i=30;i>=0;i--)
	{
		int nex=(key>>i)&1;//最好是相同的,异或为0
		if(cnt[rt][nex]==0)//这种情况莫得了
			nex=!nex;//换较差的那种
		ret=(ret<<1)+nex;
		cnt[rt][nex]--;//子节点数量减1
		rt=trie[rt][nex];//向下
	}
	return ret^key;
}
int a[maxn],b[maxn];
signed main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	init();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{//可以调换下面的顺序
		cin>>b[i];
		Insert(b[i]);
	}
	for(int i=1;i<=n;i++)
		cout<<query(a[i])<<' ';
	return 0;
}


