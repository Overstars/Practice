#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int a[maxn];
#define lowbit(x) ((x)&(-x))
ll n,x,sum1[maxn],sum2[maxn];
void add(int k,ll val)//修改:a[k]加上val,直接在c数组上操作
{
	for(int i=k;i<=n;i+=lowbit(i))//从叶子一直更新到父节点
	{
		sum1[i]+=val;//每个节点都加上val
		sum2[i]+=val*k;
	}
}
ll query1(int k)//查询[1,k]的前缀和
{
	ll ret=0;
	for(int i=k;i;i-=lowbit(i))
		ret+=sum1[i];//即求a[k]的前缀和
	return ret;
}
ll query2(int k)//查询前缀和的前缀和
{
	ll ret=0;
	for(int i=k;i;i-=lowbit(i))
		ret+=(k+1)*sum1[i]-sum2[i];
	return ret;
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int m,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		add(i,a[i]);//这里维护前缀和数组
	}
	while(m--)
	{
		string s;
		cin>>s;
		if(s[0]=='Q')
		{
			cin>>k;
			cout<<query2(k)<<endl;
		}
		else{
			cin>>k>>x;
			add(k,x-(query1(k)-query1(k-1)));
		}
	}
	return 0;
}


