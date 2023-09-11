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
struct Node
{
	int l,r;//左右儿子编号
	int val,siz;//节点权值,子树大小
	int cnt;//当前节点重复次数,默认为1
} spl[maxn];
int nodecnt,root;//内存池计数器与根结点编号
inline void newnode(int &now,int &val)
{
	spl[now=++nodecnt].val=val;
	spl[now].siz=spl[now].cnt=1;
}
inline void update(int now)
{//更新节点子树大小
	spl[now].siz=spl[spl[now].l].siz+spl[spl[now].r].siz+spl[now].cnt;
}
inline void zig(int &now)
{//now节点右旋
	int l=spl[now].l;//拎起now的左子树
	spl[now].l=spl[l].r;//l的右子树作为now的左子树
	spl[l].r=now;//now作为原本左儿子的右子树
	now=l;//向上更新编号
	update(spl[now].r),update(now);
}
inline void zag(int &now)
{
	int r = spl[now].r;
    spl[now].r = spl[r].l;
    spl[r].l = now;
    now = r;
    update(spl[now].l),update(now);
}
void splaying(int x,int &y) //我要把x伸展到y那个位置！
{
    if(x==y)
		return;//如果到了终点，return
    int &l=spl[y].l,&r=spl[y].r;//temp
    if(x==l)
		zig(y);//如果左儿子是终点，那就单旋
    else if(x==r)
		zag(y);//右儿子是终点也是单旋
    else//否则就一定是双旋
    {
        if(spl[x].val<spl[y].val)
        {//x在y左子树上
            if(spl[x].val<spl[l].val)// /型
                splaying(x,spl[l].l),zig(y),zig(y);//zigzig情况
            else// <型
				splaying(x,spl[l].r),zag(l),zig(y);//zagzig情况
        }
        else
        {//x在y右子树上
            if(spl[x].val>spl[r].val)// \型
                splaying(x,spl[r].r),zag(y),zag(y);//zagzag情况
            else// >型
				splaying(x,spl[r].l),zig(r),zag(y);//zigzag情况
        }
    }
}
inline void delnode(int now)
{
	splaying(now,root);//将要删的节点移到顶端
	if(spl[now].cnt>1)
		spl[now].siz--,spl[now].cnt--;
	else if(spl[root].r)
	{
		int p=spl[root].r;//右子树
		while(spl[p].l)//找now节点后继
			p=spl[p].l;
		splaying(p,spl[root].r);//将后继移到root右儿子
		spl[p].l=spl[root].l;//root的左子树作为p的左子树
		root=p;//p作为根节点
		update(root);//更新信息
	}
	else//没有后继,直接删除
		root=spl[root].l;
}
void ins(int &now,int &val)
{//插入
	if(!now)//不存在,新建
		newnode(now,val),splaying(now,root);
	else if(val<spl[now].val)//插到左子树上
		ins(spl[now].l,val);
	else if(val>spl[now].val)
		ins(spl[now].r,val);
	else//已存在,cnt++
		spl[now].siz++,spl[now].cnt++,splaying(now,root);
}
void del(int now,int &val)
{
    if(spl[now].val==val)
		delnode(now);
    else if(val<spl[now].val)
		del(spl[now].l,val);
    else
		del(spl[now].r,val);
}
int getrank(int val)
{
    int now=root,rnk=1;
    while(now)
    {
        if(spl[now].val==val)   //找到了要的结点，这个之前的没有
        {
            rnk+=spl[spl[now].l].siz;
            splaying(now,root);
            break;
        }
        if(val<=spl[now].val)
            now=spl[now].l;
        else
        {
            rnk+=spl[spl[now].l].siz+spl[now].cnt;
            now=spl[now].r;
        }
    }
    return rnk;
}
int getnum(int rnk)
{
    int now=root;
    while(now)
    {
        int lsize=spl[spl[now].l].siz;
        if(lsize+1<=rnk&&rnk<=lsize+spl[now].cnt) //如果在这个范围内，那就是当前结点
        {
            splaying(now,root);
            break;
        }
        else if(lsize>=rnk)
            now=spl[now].l;
        else
        {
            rnk-=lsize+spl[now].cnt;
            now=spl[now].r;
        }
    }
    return spl[now].val;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,opt,x;
	cin>>n;
	while(n--)
	{
		cin>>opt>>x;
		if(opt==1)
			ins(root,x);
		else if(opt==2)
			del(root,x);
		else if(opt==3)
			cout<<getrank(x)<<endl;
		else if(opt==4)
			cout<<getnum(x)<<endl;
		else if(opt==5)//前驱
			cout<<getnum(getrank(x)-1)<<endl;
		else//后继
			cout<<getnum(getrank(x+1))<<endl;
	}
	return 0;
}


