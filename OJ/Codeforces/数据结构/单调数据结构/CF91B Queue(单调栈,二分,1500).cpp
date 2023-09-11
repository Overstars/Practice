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
int a[maxn],stk[maxn]={inf},top,ans[maxn];
int get(int l,int r,int val)
{//数组单调递减
	int ans=0;
	while(l<=r)
	{//找出第一个>=a[i]
		int mid=(l+r)>>1;
		int p=stk[mid];
		if(a[p]>=val)
			l=mid+1;
		else{
			r=mid-1;
			ans=max(ans,p);
		}
	}
	return ans;
}
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	memset(ans,-1,sizeof(ans));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		if(!top||a[i]<a[stk[top]])
			stk[++top]=i;
		int pos=max(get(1,top,a[i]),i);
//		printf("a[%d]=%d,pos=%d\n",i,a[i],pos);
		ans[i]=pos-i-1;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}
/*
 *对每个i找到右面最远的小于a[i]的数
 *如果从右向左扫,若a[i]小于栈顶元素,压栈,否则不会比之前的更优,弹栈
 *维护一个栈底到栈顶单调递减的栈,对每个i二分出来最大位置
 *嗯,可能用单调队列更好写点,毕竟不用弹栈
*/

