//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
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
struct ChthollyTree
{
	ll qmod(ll a,ll b,ll mod)  //快速幂
	{
		ll ans=1;
		a=a%mod;
		while(b)
		{
			if(b&1)
				ans=ans*a%mod;
			a=a*a%mod;
			b>>=1;
		}
		return ans;
	}
	struct node
	{
		int l,r;//区间左右端点,[l,r]区间每个数都为val
		mutable ll val;//mutable支持直接在set中修改
		node(int _l,int _r=-1,ll _val=0):
			l(_l),r(_r),val(_val){}
		bool operator <(const node &b)const{
			return l<b.l;
		}
//		node(int _l): l(_l){}
	};
	std::set<node> s;
	void build(ll *a,int n)
	{
		s.clear();
		for(int i=1;i<=n;i++)
			s.insert(node(i,i,a[i]));
		s.insert(node(n+1,n+1,0));
	}
	#define sit std::set<node>::iterator
	sit split(int pos)
	{//将pos所在节点分为[l,pos),[pos,r]两块
		sit it=s.lower_bound(node(pos));
		if(it!=s.end()&&it->l==pos)
			return it;//正好存在,无需分裂
		it--;
		int l=it->l,r=it->r;
		ll val=it->val;
		s.erase(it);
		s.insert(node(l,pos-1,val));
		return s.insert(node(pos,r,val)).first;//insert.first为指向新增元素的迭代器
	}
	inline void assign(int l,int r,ll val)
	{//区间推平
		sit ed=split(r+1),st=split(l);
		s.erase(st,ed);
		s.insert(node(l,r,val));
	}
	inline void update(int l,int r,ll val)
	{//[l,r]加上val
		sit ed=split(r+1);//先找ed,若先找st可能会在找ed的过程中被擦除
		for(sit it=split(l);it!=ed;it++)
			it->val+=val;
	}
	ll kth(int l,int r,int k)
	{//区间第k小
		std::vector<pair<ll,int>>tmp;//数值,数量
		tmp.clear();
		sit ed=split(r+1),st=split(l);
		for(sit it=st;it!=ed;it++)
			tmp.push_back(std::pair<ll,int>(it->val,it->r-it->l+1));
		std::sort(tmp.begin(),tmp.end());
		for(std::vector<std::pair<ll,int>>::iterator it=tmp.begin();it!=tmp.end();++it)
		{
			k-=it->second;
			if(k<=0)
				return it->first;
		}
		return -1;
	}
	ll query(int l,int r,ll k,ll y)
	{//区间k次幂之和取模
		sit ed=split(r+1),st=split(l);
		ll ret=0;
		for(sit it=st;it!=ed;it++)
			ret=(ret+(it->r-it->l+1)*qmod(it->val,k,y))%y;
		return ret;
	}
} ctl;
ll seed,n,m,vmax;
ll rnd()
{
	ll ret=seed;
	seed=(seed*7+13)%1000000007;
	return ret;
}
ll a[maxn];
signed main(signed argc, char const *argv[])
{
//	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>n>>m>>seed>>vmax;
	for(int i=1;i<=n;i++)
		a[i]=(rnd()%vmax)+1;
	ctl.build(a,n);
	ll op,l,r,x,y;
	for(int i=1;i<=m;i++)
	{
		op=(rnd()%4)+1;
		l=(rnd()%n)+1;
		r=(rnd()%n)+1;
		if(l>r)
			swap(l,r);
		if(op==3)
			x=(rnd()%(r-l+1))+1;
		else
			x=(rnd()%vmax)+1;
		if(op==4)
			y=(rnd()%vmax)+1;
		if(op==1)
			ctl.update(l,r,x);
		else if(op==2)
			ctl.assign(l,r,x);
		else if(op==3)
			cout<<ctl.kth(l,r,x)<<endl;
		else
			cout<<ctl.query(l,r,x,y)<<endl;
	}
	return 0;
}


