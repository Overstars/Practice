//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e6+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
struct Node
{
	int l,r,val;//左右儿子编号,该点权值
	int height,siz;//高度,树大小
} avl[maxn];
int cnt=0,root=0;//注意初始化
inline void newnode(int &now,int val)
{//新建节点
	avl[now=++cnt].val=val;
	avl[cnt].siz=avl[cnt].height=1;
}
inline void update(int now)
{//更新节点大小和高度
	avl[now].siz=avl[avl[now].l].siz+avl[avl[now].r].siz+1;
	avl[now].height=max(avl[avl[now].l].height,avl[avl[now].r].height)+1;
}
inline int bf(int now)
{//获取平衡因子bf
	return avl[avl[now].l].height-avl[avl[now].r].height;
}
inline void lrotate(int &now)
{//now节点左旋,因为右子树过高
	int r=avl[now].r;//记录右儿子
	avl[now].r=avl[r].l;//右儿子左子树接到now右儿子上
	avl[r].l=now;//now作为r的左子树
	now=r;
	update(avl[now].l),update(now);
}
inline void rrotate(int &now)
{//now右旋
	int l = avl[now].l;
	avl[now].l = avl[l].r;
	avl[l].r = now;
	now = l;
	update(avl[now].r),update(now);
}
inline void check(int &now)
{//检查now是否需要旋转,并更新
	int nowf=bf(now);
	if(nowf>1)
	{//左子树过高
		int lf=bf(avl[now].l);
		if(lf>0)//now左儿子的左子树过高,LL
			rrotate(now);//右旋now节点
		else//now左儿子右子树过高,LR
			lrotate(avl[now].l),rrotate(now);
	}//左旋左儿子,再右旋now
	else if(nowf<-1)
	{//右子树过高
		int rf=bf(avl[now].r);
		if(rf<0)//RR
			lrotate(now);
		else//RL
			rrotate(avl[now].r),lrotate(now);
	}
	else if(now)//平衡且非空
		update(now);
}
void ins(int &now,int val)
{
	if(!now)//不存在则新建
		newnode(now,val);
	else if(val<avl[now].val)
		ins(avl[now].l,val);
	else
		ins(avl[now].r,val);
	check(now);
}
int find(int &now,int fa)
{//找到以id为根的子树上最小的那个点(没有左儿子),并返回编号
	int ret;
	if(!avl[now].l)//没有左儿子了,说明已找到
	{
		ret=now;//相当于这个叶子节点暂时删掉了
		avl[fa].l=avl[now].r;//右子树替换该点,接到父节点左儿子上
	}
	else{
		ret=find(avl[now].l,now);//左子树上继续找
		check(now);//回溯调整
	}
	return ret;//返回找到的节点编号
}
void del(int &now,int val)
{
	if(val==avl[now].val)//要删除的结点
	{
		int l=avl[now].l,r=avl[now].r;
		if(!l||!r)//叶子节点或者只有一个儿子
			now=l+r;//直接将编号改为子节点
		else
		{//在右子树上找后继
			now=find(r,r);//后继替换删除节点位置,连接左右儿子
			if(now!=r)//后继不是删除节点的右儿子,否则本来是连接好的不必更改
				avl[now].r=r;//now右儿子改成删除节点右儿子
			avl[now].l=l;//now左儿子改成删除节点左儿子
		}
	}
	else if(val<avl[now].val)
		del(avl[now].l,val);//左子树上找
	else
		del(avl[now].r,val);//右子树上找
	check(now);//递归回溯检查
}
int getrnk(int val)
{//传入值查询排名
	int now=root,ans=1;
	while(now)//没到达叶子节点
	{
		if(val<=avl[now].val)
			now=avl[now].l;//在now左子树上找
		else{//在右子树上找
			ans+=avl[avl[now].l].siz+1;//左子树与now节点都比val小
			now=avl[now].r;
		}
	}
	return ans;
}
int getval(int rnk)
{
	int now=root;
	while(now)
	{//每轮在now子树上找第rnk大
		if(avl[avl[now].l].siz+1==rnk)
			break;//找到了,now就是
		else if(avl[avl[now].l].siz>=rnk)
			now=avl[now].l;//rnk在左子树上
		else{//减去左子树和now节点,并在右子树上找
			rnk-=avl[avl[now].l].siz+1;
			now=avl[now].r;
		}
	}
	return avl[now].val;
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,m,op,x,last=0,ans=0;
	read(n,m);
	for(int i=1;i<=n;i++)
		read(x),ins(root,x);
	while(m--)
	{
		read(op,x);
		x^=last;
//		printf("trans;%d %d\n",op,x);
		switch(op)
		{
		case 1:
			ins(root,x);
			break;
		case 2:
			del(root,x);
			break;
		case 3://给值查排名
			last=getrnk(x);
			break;
		case 4://给排名查值
			last=getval(x);
			break;
		case 5://前驱
			last=getval(getrnk(x)-1);
			break;
		case 6://后继
			last=getval(getrnk(x+1));
			break;//可能有多个x,所以要+1
		}
		if(op>2)
			ans^=last;
//		printf("last=%d,ans=%d\n",last,ans);
	}
	printf("%d\n",ans);
	return 0;
}


