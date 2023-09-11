#include<bits/stdc++.h>
using namespace std;
const int maxn=1E5+5;
const double alpha=0.75;
struct node
{
	int l,r,val;
	int siz,fact;
	bool exist;
} tzy[maxn];
int cnt,root;
void newnode(int &now,int val)//新建节点
{
	now=++cnt;
	tzy[now].val=val;
	tzy[now].siz=tzy[now].fact=1;
	tzy[now].exist=1;
}
bool imbalence(int now)
{
	if(max(tzy[tzy[now].l].siz,tzy[tzy[now].r].siz)>tzy[now].siz*alpha)
		return 1;//最大子树大小大于now*平衡因子
	if(tzy[now].siz-tzy[now].fact>tzy[now].siz*0.3)
		return 1;//已删除节点超过30%
	return 0;
}
vector<int> v;//储存重构树中未删除节点中序遍历编号(有序)
void ldr(int now)//中序遍历
{
	if(!now)
		return;
	ldr(tzy[now].l);
	if(tzy[now].exist)//舍弃所有删除点
		v.push_back(now);
	ldr(tzy[now].r);
}
void lift(int l,int r,int &now)
{
	if(l==r)//叶子节点
	{
		now=v[l];
		tzy[now].l=tzy[now].r=0;//子节点不存在
		tzy[now].siz=tzy[now].fact=1;
		return;
	}
	int mid=(l+r)>>1;
	while(mid&&l<mid&&tzy[v[mid]].val==tzy[v[mid-1]].val)
		mid--;//将相同元素都放在右子树
	now=v[mid];//修改父节点连接的左右子树
	if(l<mid)
		lift(l,mid-1,tzy[now].l);//这里面传递左右引用下去,会自动修改节点间的父子关系
	else
		tzy[now].l=0;
	lift(mid+1,r,tzy[now].r);//因为向下取整,右子树一定存在
	tzy[now].siz=tzy[tzy[now].l].siz+tzy[tzy[now].r].siz+1;
	tzy[now].fact=tzy[tzy[now].l].fact+tzy[tzy[now].r].fact+1;
}
void rebuild(int &now)//暴力重构
{
	v.clear();
	ldr(now);//中序遍历
	if(v.empty())
	{
		now=0;
		return;
	}
	lift(0,v.size()-1,now);//从中间拎起来
}
void update(int now,int ed)//头递归自底向上更新siz信息
{
	if(!now)
		return;
	if(tzy[ed].val<tzy[now].val)
		update(tzy[now].l,ed);
	else
		update(tzy[now].r,ed);
	tzy[now].siz=tzy[tzy[now].l].siz+tzy[tzy[now].r].siz+1;
}
void check(int &now,int ed)//从根节点一直检查到ed
{
	if(now==ed)
		return;
	if(imbalence(now))//不平衡
	{
		rebuild(now);//暴力重构
		update(root,now);//向上更新siz信息
		return;
	}
	if(tzy[ed].val<tzy[now].val)
		check(tzy[now].l,ed);//检查受更新影响的子树是否需要重构
	else
		check(tzy[now].r,ed);
}
void ins(int &now,int val)//插入,传递引用
{
	if(!now)//到了叶子节点下面
	{
		newnode(now,val);//这里修改了now的值,相当于父节点的"指针"指向这里
		check(root,now);//检查是否需要重构
		return;
	}
	tzy[now].siz++;
	tzy[now].fact++;
	if(val<tzy[now].val)//比当前值小
		ins(tzy[now].l,val);//向当前节点左子树插入
	else
		ins(tzy[now].r,val);//否则插到右子树
}
void del(int now,int val)//删除
{
	if(tzy[now].exist&&tzy[now].val==val)//找到
	{
		tzy[now].exist=0;
		tzy[now].fact--;//实际大小-1
		check(root,now);//从根节点开始检查是否失衡
		return;
	}
	tzy[now].fact--;//所有祖先节点实际大小--
	if(val<tzy[now].val)//向下找
		del(tzy[now].l,val);
	else
		del(tzy[now].r,val);
}
int getrank(int val)//查询val的排名
{
	int now=root,rak=1;
	while(now)//
	{
		if(val<=tzy[now].val)//val比当前结点权值小
		{
			now=tzy[now].l;//到左子树上查询
		}
		else{//rak+=左子树大小+当前节点是否存在
			rak+=tzy[now].exist+tzy[tzy[now].l].fact;
			now=tzy[now].r;//到右子树查询
		}
	}
	return rak;
}
int getnum(int rak)//查询排名的值
{
	int now=root;
	while(now)
	{
		if(tzy[now].exist&&tzy[tzy[now].l].fact+tzy[now].exist==rak)
			break;//左子树实际大小+当前节点存在==rak,则当前节点即为目标
		else if(tzy[tzy[now].l].fact>=rak)
			now=tzy[now].l;//一定在当前节点左子树,到左子树上查询
		else{//减掉当前个数,到右子树上找
			rak-=tzy[tzy[now].l].fact+tzy[now].exist;
			now=tzy[now].r;
		}
	}
	return tzy[now].val;
}
int main()
{
	int n,ope,x;
	cin>>n;
	while(n--)
	{
		cin>>ope>>x;
		switch(ope)
		{
		case 1:
			ins(root,x);
			break;
		case 2:
			del(root,x);
			break;
		case 3://查询数x的排名
			cout<<getrank(x)<<'\n';
			break;
		case 4://查询排名x的数
			cout<<getnum(x)<<'\n';
			break;
		case 5://给出数,查询前驱
			cout<<getnum(getrank(x)-1)<<'\n';
			break;
		case 6://给一个数,查后继(不一定在树上)
			cout<<getnum(getrank(x+1))<<'\n';
			break;//
		}
	}
	return 0;
}
