//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
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
int h[maxn],q[maxn],head=1,tail=0;
int stk[maxn],top=0,stk2[maxn],top2=0;
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	for(int i=1;i<=n;i++)
	{
		while(top&&h[stk[top]]>=h[i])//>=都会弹出去,等于时只会是离i最近的
			top--;
		while(top2&&h[stk2[top2]]<h[i])
			top2--;
		int p1=stk2[top2];//最近的>=h[i]的位置,在之后求第一个左端点
		int l=lower_bound(stk+1,stk+top+1,p1)-stk;
		if(top&&l<top+1)
		{
//			printf("[%d,%d]\n",l,i);
			ans=max(ans,i-stk[l]+1);
		}
		stk[++top]=i;
		stk2[++top2]=i;
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *对于每个i找到最左面
 *从左向右扫时维护一个单调递增的队列
 *哦中间不一定是递增的...
 *单调栈:第一个维护i之前<h[i]的下标,第二个维护i之前>=h[i]的下标
 *
 *思考题:若l和r是中间最高的,如何维护
*/
//		while(head<=tail&&h[q[tail]]>=h[i])
//			tail--;
//		q[++tail]=i;
//		if(head<tail)
//			ans=max(ans,q[tail]-q[head]+1);
