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
struct node
{
	int l,r;//区间左右端点,[l,r]区间每个数都为val
	mutable bool val;//mutable支持直接在set中修改
	node(int _l,int _r=-1,bool _val=0):
		l(_l),r(_r),val(_val){}
	bool operator <(const node &b)const{
		return l<b.l;
	}
//		node(int _l): l(_l){}
};
ll ans=0;
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
	inline void assign(int l,int r,bool val)
	{//区间推平
		sit ed=split(r+1),st=split(l);
		for(sit it=st;it!=ed;it++)
			ans-=it->val*(it->r-it->l+1);
		s.erase(st,ed);
		s.insert(node(l,r,val));
		ans+=val*(r-l+1);
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
	ll count(int l,int r,bool val)
	{
		ll ans=0;
		sit ed=split(r+1),st=split(l);
		for(sit it=st;it!=ed;it++)
			if(it->val==val)
				ans+=it->r-it->l+1;
		return ans;
	}
} ctl;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,q,l,r,k;
	read(n,q);
//	cin>>n;
	ans=n;
	ctl.s.insert(node(1,n,1));
//	for(int i=1;i<=n;i++)
//		ctl.s.insert(node(i,i,1));
	ctl.s.insert(node(n+1,n+1,0));
//	cin>>q;
	while(q--)
	{
		read(l,r,k);
//		cin>>l>>r>>k;
		if(k==1)
			ctl.assign(l,r,0);
		else
			ctl.assign(l,r,1);
		printf("%lld\n",ans);
//		cout<<ans<<endl;
//		cout<<ctl.count(1,n,1)<<endl;
	}
	return 0;
}


