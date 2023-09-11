#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
ll h[maxn],stk[maxn],s2[maxn],top2=0,top=0;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	ll n;
	while(cin>>n&&n)
	{
		for(int i=1;i<=n;i++)
			cin>>h[i];
		ll ans=0;
		top=top2=0;
		for(int i=1;i<=n;i++)
		{
			while(top&&h[stk[top]]>=h[i])
			{
				int now=stk[top];
				top--;
				if(top)
					ans=max(ans,h[now]*(i-stk[top]));
			}
			stk[++top]=i;
		}
//		for(int i=1;i<=n;i++)//维护一个单增的栈...
//		{
//			ans=max(ans,h[i]);
//			while(top&&h[stk[top]]>h[i])//高度>h[i],弹栈
//			{
//				ans=max(ans,h[i]*(i-stk[top]+1));
////				printf("ans[%d]=%lld\n",i,ans);
//				top--;
//			}
//			stk[++top]=i;
//			if(top)
//				ans=max(ans,h[stk[1]]*(stk[top]-stk[1]+1));
//			for(int j=0;top>j&&h[stk[top-j]]==h[i];j++)//栈中等于,计算贡献,不弹出
//			{
//				ans=max(ans,h[stk[top-j]]*(i-stk[top-j]+1));
//			}
//			while(top2&&h[s2[top2]]<h[i])//维护单减栈
//			{
//				top2--;
//			}
//			s2[++top2]=i;
//			if(top2)
//			{
//				ans=max(ans,h[i]*(i-s2[1]+1));
////				printf("%lld,%lld:%lld\n",h[i],h[s2[1]],ans);
//			}
////			for(int j=0;top2>j&&h[s2[top2-j]]==h[i];j++)//栈中等于,计算贡献,不弹出
////			{
////				ans=max(ans,h[i]*(i-s2[top-j]+1));
////			}
//			printf("%d:单增栈:",i);
//			for(int j=1;j<=top;j++)
//				printf("h[%lld]=%lld%c",stk[j],h[stk[j]],j==top?'\n':' ');
//			printf("单减栈:");
//			for(int j=1;j<=top2;j++)
//				printf("h[%lld]=%lld%c",s2[j],h[s2[j]],j==top2?'\n':' ');
//			printf("ans[%d]=%lld\n",i,ans);
//		}
////		for(int i=1;i<=top;i++)//不能忽略中间凹陷...
////			ans=max(ans,h[stk[i]]*(stk[top]-stk[i]+1));
		cout<<ans<<endl;
	}
	return 0;
}


