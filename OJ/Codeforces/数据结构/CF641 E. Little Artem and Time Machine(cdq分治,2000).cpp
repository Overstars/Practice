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
struct opt
{
	int id,op,t,x;
	opt(int a=0,int b=0,int c=0,int d=0):
		id(a),op(b),t(c),x(d){}
	bool operator < (const opt &y)const{
		return t>y.t;
	}
} a[maxn];
vector<bool>ok;
vector<int>ans,mp,v1;
void cdq(int l,int r)
{
	if(l==r)
		return;
	int mid=(l+r)>>1;
	cdq(l,mid);
	cdq(mid+1,r);
	sort(a+l,a+mid+1);//区间内按t排序
	sort(a+mid+1,a+r+1);//[l,mid]操作早于[mid+1,r]
	int i=mid+1,j=l;
	for(;i<=r;i++)
	{//在这前面的操作,且时间点t也在前面,则j对i有影响
		for(;a[j].t<=a[i].t&&j<=mid;j++)//双指针维护t这一维
		{
			if(a[j].op==1)
				mp[a[j].x]++;
			else if(a[j].op==2)
				mp[a[j].x]--;
		}
		if(a[i].op==3)//影响累计
			ans[a[i].id]+=mp[a[i].x];
	}
	for(j--;j>=l;j--)//j前面的才做出了有效贡献的
		if(a[j].op!=3)//桶清空
			mp[a[j].x]+=(a[j].op==1?-1:1);
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int q,op,t,x;
	cin>>q;
	ans.resize(q+1,0);
	mp.resize(q+1,0);
	ok.resize(q+1,0);//标记哪些是询问
	for(int i=1;i<=q;i++)
	{
		cin>>op>>t>>x;
		a[i]=opt(i,op,t,x);//操作顺序,操作类型,时间点t,数值x
		if(op==3)
			ok[i]=1;
		v1.push_back(x);//离散化要用
	}
	sort(v1.begin(),v1.end());
	v1.erase(unique(v1.begin(),v1.end()),v1.end());
	for(auto &i:a)//离散化,map也行
		i.x=lower_bound(v1.begin(),v1.end(),i.x)-v1.begin()+1;
	cdq(1,q);
	for(int i=1;i<=q;i++)
		if(ok[i])//第i是询问
			cout<<ans[i]<<endl;
	return 0;
}
/*
 *怎么感觉像是平衡树...
 *不过是奔着cdq来的
 *没看懂按操作顺序来还是按时间顺序来
 *样例一第一个询问是因为第五次操作在时间点3删掉了一个5吗?
 *还是因为这之前只在在时间点1插入了一个5?
 *应该后面的操作不会影响前面的,将操作顺序排序
 *开个桶记录x的值
 *操作顺序是一维,跳跃时间点是一维,双指针维护
 */

