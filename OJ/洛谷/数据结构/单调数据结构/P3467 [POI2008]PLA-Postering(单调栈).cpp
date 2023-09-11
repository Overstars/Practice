#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
int stk[maxn],top=0;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,ans=0,d,w;
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>d>>w;
		while(top&&stk[top]>=w)//弹栈
		{
			if(stk[top]==w)//和前面的某一张等高,中间的全都大于这两张的高(边角补全)
				ans--;
			top--;
		}
		stk[++top]=w;
	}
	cout<<ans<<endl;
	return 0;
}
/*
 *给你由n个矩形排成一排构成的图形
 *将这个图形完整切割成矩形,最少可以切多少个
 */


