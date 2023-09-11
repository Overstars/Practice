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
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct LeftistTree
{
	/*
	 * 在保持二叉堆基础性质上可以快速合并的堆
	 * 外节点:左右儿子不完整的节点
	 * 距离:最近的外节点到该点的距离
	 * 性质:
	 * 1.节点权值不大于左右儿子权值(堆性质)
	 * 2.节点左儿子距离≥右儿子距离(左偏性质)
	 * 3.节点距离=右儿子距离+1
	 * 支持如下操作:
	 * 合并两个堆 merge,log(p+q)
	 * 插入 push ,log(n)
	 * 删除最值 pop ,log(n)
	 * 删除指定节点 ,log(n)
	 * 修改指定节点的值:先删除再加入
	 * 取最大/最小值 ,O(1)
	 * lt.sum[lt.findfa(x)],可以得到x所在堆的元素和
	 * lt.cnt[lt.findfa(x)],可以得到x所在堆的大小
	 * build可快速建树,暴建树力建树nlogn
	*/
	using type=int;
	int siz=0;
	struct node
	{
		type val;
		int lc,rc,dis,fa;
		node(){}
		node(type val):
			val(val){lc=rc=dis=fa=0;}
	} ltt[maxn];
	type sum[maxn];//堆中元素之和
	int cnt[maxn];//每一个堆的大小
	#define ls(x) ltt[x].lc
	#define rs(x) ltt[x].rc
	inline void update(int x)
	{
		sum[x]=sum[ls(x)]+sum[rs(x)]+ltt[x].val;//更新堆中元素和
//		printf("node[%d],l=%d,r=%d\n",x,ls(x),rs(x));
		cnt[x]=cnt[ls(x)]+cnt[rs(x)]+1;
		if(ltt[ls(x)].val==-1)
		{
			sum[x]-=sum[ls(x)];
			cnt[x]-=cnt[ls(x)];
		}
//		printf("cnt[%d]=%d+%d+1=%d\n",x,cnt[ls(x)],cnt[rs(x)],cnt[x]);
//		printf("sum[%d]=%d=%d+%d+%d\n\n",x,sum[x],sum[ls(x)],sum[rs(x)],ltt[x].val);
	}
	int merge(int x,int y)
	{//x,y为堆顶点元素的编号
		if(x==y)//相同堆不合并
			return x;
//		printf("%d,%d\n",x,y);
		if(!x||!y)//如果有一个为空
			return x+y;//就返回另一个
		if(ltt[x].val<ltt[y].val||(ltt[x].val==ltt[y].val&&x>y))//大根堆
			std::swap(x,y);
//		printf("%d:ls=%d,rs=%d\n",x,ls(x),rs(x));
		rs(x)=merge(rs(x),y);//往右儿子合并
		ltt[rs(x)].fa=x;
		update(x);//回溯更新新树信息
		if(ltt[ls(x)].dis<ltt[rs(x)].dis)
			std::swap(ls(x),rs(x));
		ltt[x].dis=ltt[rs(x)].dis+1;
		return x;//返回新的根编号
	}
	void Merge(int x,int y)
	{//合并x所在堆与y所在堆
//		if(ltt[x].val==-1||ltt[y].val==-1)//根据需要注释
//			return;
		int fx=findfa(x),fy=findfa(y);
		if(fx==fy)
			return;
		ltt[fx].fa=ltt[fy].fa=merge(fx,fy);//维护联通性
	}
	int push(int val,int x)
	{//新加入的点权val,准备加入的堆根编号x
		ltt[++siz].val=val;
		ltt[siz].fa=siz;
		ls(siz)=rs(siz)=ltt[siz].dis=0;
		cnt[siz]=1;
		sum[siz]=ltt[siz].val;
		return merge(siz,x);//当作一棵新树合并到原树上
	}
	int findfa(int x)
	{//获得第x号所在堆的顶点编号
		if(ltt[x].fa!=x)//路径压缩
			return ltt[x].fa=findfa(ltt[x].fa);
		return x;
	}
	type top(int x)
	{//返回x所在堆的顶点的值
		return ltt[findfa(x)].val;
	}
	int pop(int x)
	{//x为当前堆根编号,并且删除x节点
		if(ltt[x].val==-1)//已经被删除
			return -1;
		ltt[x].val=-1;//将节点x标记为删除
		ltt[ls(x)].fa=ls(x);
		ltt[rs(x)].fa=rs(x);//将左右子树合并,并用并查集维护联通
		return ltt[x].fa=merge(ls(x),rs(x));//返回新的根编号
	}
	void del(int x)//待修改,错的
	{//O(logn)删除任意节点,x为节点编号
		int fx=ltt[x].fa,p=merge(ls(x),rs(x));//将左右子树合并
		int &lls=ls(fx),&rrs=rs(x);
		ltt[p].fa=fx;
		if(lls==x)//新子树连接到x原来的父节点
			lls=p;
		else
			rrs=p;
		while(p!=fx)
		{//检查左偏树性质
			if(ltt[lls].dis<ltt[rrs].dis)
				swap(lls,rrs);
			if(ltt[lls].dis==ltt[rrs].dis+1)
				return;
			ltt[fx].dis=ltt[rrs].dis+1;
			p=fx;//向上
			fx=ltt[fx].fa;
			lls=ls(fx);
			rrs=rs(fx);
		}
	}
	int build(int a[],int n)//未验证
	{//将[1,n]的元素全部合并
		ltt[0].dis=-1;
		queue<int>q;
		for(int i=1;i<=n;i++)
		{//处理节点信息
			ltt[i].val=a[i];
			ltt[i].fa=i;
			ls(i)=rs(i)=0;
			q.push(i);
		}
		siz=n;
		while(!q.empty())
		{//队列优化建树
			if(q.size()==1)
				break;
			else{
				int x=q.front();q.pop();
				int y=q.front();q.pop();
				q.push(merge(x,y));
			}
		}
		return q.front();//返回堆根编号
	}
	#undef ls
	#undef rs
} lt;
//struct ninja
//{
//	int b,c,l;//上级b,薪水c,领导力l
//	ninja(){}
//	ninja(int b,int c,int l):
//		b(b),c(c),l(l){}
//} r[maxn];
int a[maxn],b[maxn],c[maxn],l[maxn];
int ans=0,m,cnt[maxn];
vector<int>G[maxn];
void dfs(int x)
{
	for(int &v:G[x])
	{
		dfs(v);
//		printf("Merge(%d,%d)\n",x,v);
		lt.Merge(x,v);//合并子树
	}
	while(lt.sum[lt.findfa(x)]>m)
	{
//		printf("%d\n",lt.pop(lt.findfa(x)));
		lt.pop(lt.findfa(x));
	}
//	printf("%d:sum=%d,cnt=%d\n",x,lt.sum[lt.findfa(x)],lt.cnt[lt.findfa(x)]);
	ans=max(ans,l[x]*lt.cnt[lt.findfa(x)]);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	#define DEBUG
	#ifdef DEBUG
		freopen("P3377_5.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n>>m;//个数,预算
	for(int i=1;i<=n;i++)
	{
		cin>>b[i]>>c[i]>>l[i];
		G[b[i]].push_back(i);
		lt.push(c[i],i);
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
/*
 * 2021-04-20-14.15.43
 * 每个忍者都有一个上级,形成一个树形结构
 * 满意度=管理者领导力水平
 * dp[x]=l[x]*cnt,cnt为x子树上权值和不超过m的最大数量
 * 使用大根堆,不断弹栈来保证总和<=m
 */

