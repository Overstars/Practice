#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll gcd(ll a,ll b)
{
	if(a<b)
		swap(a,b);
	ll r;
	while((r=a%b)){
		a=b;
		b=r;
	}
	return b;
}
ll lcm(ll a,ll b)
{
	return (a*b)/gcd(a,b);
}
struct node
{
	int l,r,id;
	node(int l,int r,int id):
		l(l),r(r),id(id){}
	bool operator < (const node &a) const
	{
		return r<a.r;
	}
};
int a[maxn],ans[maxn];
vector<int> v[maxn];//查询因子x存在于哪些下标
vector<node> p[maxn];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,q,l,r,x;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=1;j*j<=x;j++)
		{
			if(x%j==0)
			{
				v[j].push_back(i);
				if(j*j!=x)
					v[x/j].push_back(i);
			}
		}
	}
	for(int i=1;i<=q;i++)//离线
	{//肯定是在[l,r]之间挑一个嘞
		cin>>l>>r>>x;
		for(int j=1;j*j<=x;j++)
			if(x%j==0)
			{
				p[j].push_back(node(l,r,i));
				if(j*j!=x)
					p[x/j].push_back(node(l,r,i));
			}
	}
	for(int i=1;i<maxn;i++)//枚举因子
	{
		if(v[i].size()==0)
			continue;
		sort(p[i].begin(),p[i].end());//含有因子i的询问
		int k=0;//处理含有因子i的第k个问题
		while(k<p[i].size()&&p[i][k].r<v[i][0])
			k++;//该询问区间[l,r]内无因子i
		for(int j=0;j<v[i].size()-1;j++)
		{//枚举因子i的第j个位置
			while(k<p[i].size()&&p[i][k].r<v[i][j+1])
			{//当下一个位置仍在区间右侧时
				if(p[i][k].l<=v[i][j])//在[l,r]范围内,更新
					ans[p[i][k].id]=max(ans[p[i][k].id],i);
				k++;
			}
		}
		while(k<p[i].size())
		{
			if(p[i][k].l<=v[i][v[i].size()-1])
				ans[p[i][k].id]=max(ans[p[i][k].id],i);
			k++;
		}
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
	return 0;
}


