//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=1e6+10,inf=0x3f3f3f3f,mod=1000000007;
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
int c[maxn],n;
void modify(int x,int val)
{
	while(x<=n)
	{
		c[x]=min(val,c[x]);
		x+=x&(-x);
	}
}
int query(int l,int r)
{
	int ret=inf;
	while(r>=l)
	{
		ret=min(ret,c[r]);
		r--;

	}
	return ret;
}
char s[maxn];
int sum[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	cin>>s+1;
	int ans1=0,ans2=1,MAX=0;
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		c[i]=inf;
	map<int,int>pos,cnt;
	map<int,int>::iterator it;
	pos[0]=0,cnt[0]=1;
	for(int i=1;i<=n;i++)
	{
		int val=1;
		if(s[i]==')')
			val=-1;
		sum[i]=sum[i-1]+val;
//		printf("sum[%d]=%d\n",i,sum[i]);
		if(pos.count(sum[i])==0)
		{
			pos[sum[i]]=i;
		}
		else{
			int len=i-pos[sum[i]];
			cnt[len]++;
			ans1=max(ans1,len);
//			if()//中间不能有不合法
		}
		it=pos.upper_bound(sum[i]);
		pos.erase(it,pos.end());
	}
	cout<<ans1<<' '<<cnt[ans1]<<endl;
	return 0;
}
/*
 *2021-04-11-11.09.06
 *最长合法括号序列,输出长度与数量
 *转换成+1,-1,前缀和相等的
 *pos只记录最早的
 *注意两个相等的值之间,不能有不合法的值(凹
*/

