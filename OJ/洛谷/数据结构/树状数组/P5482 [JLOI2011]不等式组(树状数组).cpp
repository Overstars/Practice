#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define int ll
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
struct BinaryIndexedsTree
{
	int n;
	ll c[maxn],sum[maxn];//c维护差分数组,sum维护i*c[i]的前缀和
	inline int lowbit(int x)
	{
		return x & (-x);
	}
	void build(int *a,int n)//a是原数组,n是元素个数
	{
		this->n=n;
		memset(c,0,sizeof(c));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
			add(i,a[i]-a[i-1]);//构建差分c数组
	}
	void add(int k,ll val)//修改:a[k]加上val,直接在c数组上操作
	{//请使用区间更新
		for(int i=k;i<=n;i+=lowbit(i))//从叶子一直更新到父节点
			c[i]+=val,sum[i]+=val*(k-1);//每个节点都加上val
	}
	void radd(int l,int r,ll val)//区间更新
	{
		add(l,val);//把l之后所有的点都更新一遍
		add(r+1,-val);//因为r之后的点是不用更新的,但是多更新了,所以要每个点都-val；
	}
	ll query(int k)//查询:c[i]前缀和的前缀和,即a[i]的前缀和
	{//节点i的长度为lowbit(i)
		ll ret=0;
		for(int i=k;i;i-=lowbit(i))
			ret+=k*c[i]-sum[i];
		return ret;
	}
} bit1,bit2;
struct node
{//1插2删3查询
	int op,a,b,c,id;
	node(int x=0,int y=0,int z=0,int w=0,int id=0):
		op(x),a(y),b(z),c(w),id(id){}
	friend ostream& operator << (ostream&,node&);
} f[maxn];
ostream& operator << (ostream& os,node& x) //定义运算符“<<”重载函数
{
   os<<"op="<<x.op<<",a="<<x.a<<",b="<<x.b<<",c="<<x.c<<",id="<<x.id;
   return os;
}
struct
{
	int a,b,c;
} ine[maxn];
bool ins[maxn];
int Index=0,allright=0;//记录不等式
int get(int pos)//传入不等式编号
{
	int a=ine[pos].a,b=ine[pos].b,c=ine[pos].c;
	if(ine[pos].a<0)//向下取整
	{
		if((c-b)%(-a)==0)//能整除
			return (c-b)/a-1;
		else if(c-b>0)//-3.5 -> -4
			return (c-b)/a-1;
		else
			return (c-b)/a;
	}
	else if(ine[pos].a>0)//向上取整
	{
		if(c-b>=0||(c-b)%a==0)
			return (c-b)/a+1;
		else
			return (c-b)/a;
	}
	//a=0特殊处理
}
vector<int>vec;
//map<int,int>ftoi;
inline int mp(int x)
{
	return lower_bound(vec.begin(),vec.end(),x)-vec.begin()+1;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("P5482_1.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,T,op,a,b,c,x;
//	cout<<-5/2<<endl;
//	cout<<(2-6)/-2<<endl;
	string s;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>s;
		if(s[0]=='A')
			op=1;
		else if(s[0]=='D')
			op=2;
		else
			op=3;
		b=c=0;
//		if(op==2)//删除的编号也要对应上
//			f[i].Index=ftoi[a];
		if(op==1)
		{
			cin>>a>>b>>c;
			ine[++Index]={a,b,c};//编号
		}
		else
			cin>>a;
		f[i]=node(op,a,b,c,Index);//离线
		if(op==1&&a!=0)
			vec.push_back(get(Index));//,printf("pos=%d\n",get(Index));
		else if(op==3)
			vec.push_back(a);
//		cout<<"fff"<<f[i]<<endl;
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	int MAX=vec.size();
	bit1.n=bit2.n=MAX;
	for(int i=1;i<=T;i++)
	{
//		cout<<f[i]<<endl;
		if(f[i].op==1)
		{
			ins[f[i].id]=1;
			if(ine[f[i].id].a==0)
			{
				if(ine[f[i].id].b>ine[f[i].id].c)
					allright++;
				continue;
			}
			int now=get(f[i].id),pos=mp(now);
			if(ine[f[i].id].a>0)
				bit1.radd(pos,pos,1);
			else
				bit2.radd(pos,pos,1);
//			cout<<"pos="<<pos<<endl;
		}
		else if(f[i].op==2)
		{
			if(!ins[f[i].a])//删过了
				continue;
			ins[f[i].a]=0;
			if(ine[f[i].a].a==0)
			{
				if(ine[f[i].a].b>ine[f[i].a].c)
					allright--;
				continue;
			}
			int now=get(f[i].a),pos=mp(now);
			if(ine[f[i].a].a>0)
				bit1.radd(pos,pos,-1);
			else
				bit2.radd(pos,pos,-1);
		}
		else{
			ll ans=allright;
			ans+=bit1.query(mp(f[i].a));//左面的都可以
			ans+=bit2.query(MAX)-bit2.query(mp(f[i].a)-1);//右面的都可以
//			cout<<allright<<'+'<<bit1.query(1)-bit1.query(mp(f[i].a)+1)<<'+'<<bit2.query(mp(f[i].a)-1)<<endl;
			cout<<ans<<endl;
		}
//		printf("???\n");
	}
//	system("pause");
	return 0;
}


