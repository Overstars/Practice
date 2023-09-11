//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=5e4+10,inf=0x3f3f3f3f,mod=1000000007;
const double eps=1e-10;
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
	ll p,a;
	node(){}
	node(ll p,ll a):
		p(p),a(a){}
	bool operator <(const node &x)const
	{
		if(p!=x.p)
			return p>x.p;
		return a>x.a;
	}
	bool operator == (const node& y) const { return p == y.p && a == y.a; }
	friend ostream & operator<<(ostream & os,const node & c);
} r[maxn];
ostream & operator<<(ostream & os,const node & x)
{
	os<<"p="<<x.p<<",a="<<x.a;
	return os;
}
int stk[maxn];//存储编号
int top=0;
vector<node>now;//筛掉相同的p,a更小的那些以及p,a都小的
double get(int x,int y)
{
	return (double)(now[x].p-now[y].p)/(double)(now[y].a-now[x].a);
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll t,n,p,a;
	cin>>t;
	while(t--)
	{
		cin>>n;
		map<node,int>mp;
//		ll maxp=0,maxa=0,ok=1;
		for(int i=1;i<=n;i++)
		{
			cin>>r[i].p>>r[i].a;
			mp[r[i]]++;
		}
		sort(r+1,r+n+1);
//		if(n>1&&r[n].p==r[n-1].p&&r[n].a==r[n-1].a)
//		{
//			cout<<0<<endl;
//			continue;
//		}
		now.clear();
		for(int i=1;i<=n;i++)//下一个一定会在某时刻超过上一个
		{
			if(now.empty()||r[i].a>now[now.size()-1].a)
			{
//				if(r[i].p==maxp&&r[i].a==maxa&&r[i].p==r[i-1].p&&r[i].a==r[i-1].a)
//					ok=0;
//				cout<<"wtf!!"<<r[i]<<endl;
				now.push_back({r[i].p,r[i].a});
			}
		}
//		if(!ok)
//		{
//			cout<<0<<endl;
//			continue;
//		}
//		top=0;
//		for(auto &x:now)
//			cout<<"wtf"<<x.p<<' '<<x.a<<endl;
		stk[top=1]=0;
		for(int i=1;i<now.size();i++)
		{
//			if(get(stk[top],i)<=eps)//if(abs(now[x].a-now[y].a)<eps)
//				continue;
//			cout<<get(stk[top-1],stk[top])<<"-"<<get(stk[top],i)<<endl;
			while(top>=2&&abs(get(stk[top-1],stk[top])-get(stk[top],i))<=eps)//早于上一个超车时间
				top--;
			while(top>=2)
			{
				ll A1=now[stk[top-1]].p-now[stk[top]].p,A2=now[stk[top]].p-now[i].p;
				ll B1=now[stk[top]].a-now[stk[top-1]].a,B2=now[i].a-now[stk[top]].a;
//				cout<<"A1/B1="<<A1<<"/"<<B1<<","<<"A2/B2"<<A2<<"/"<<B2<<endl;
				if(A1*B2<A2*B1)//早于i与top超车时间
					break;
//				cout<<"imposiible!"<<endl;
				top--;//晚于的全部出栈,维护单调递增
			}
			stk[++top]=i;
		}
		int ans=0;
		for(int i=1;i<=top;i++)
		{
			if(mp[now[stk[i]]]==1)
				ans++;
//			cout<<now[stk[i]]<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
*存在相同的a
1
2
7 6
4 6
ans=1
*后超车的被重复元素覆盖
1
6
7 2
2 7
6 7
6 7
6 1
5 5
ans=1
*多个交点集中在一起
1
4
7 3
5 5
4 6
3 7
ans=2
*再来一组
1
3
6 2
5 5
4 6
ans=3
*/

