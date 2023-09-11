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
int a[maxn],inc[maxn],des[maxn];
int mi1[maxn],mi2[maxn];
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		a[0]=inf;
		bool ok=1;
		int cnt=0,pos=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<a[pos])
				pos=i;
			mi1[i]=pos;
		}
		pos=0;
		for(int i=n;i>=1;i--)
		{
			if(a[i]<a[pos])
				pos=i;
			mi2[i]=pos;
			if(mi1[i]!=pos&&a[mi1[i]]+a[pos]<a[i])
				ok=0;
			else if(a[pos]<a[i])
				ok=0;
		}
//		a[0]=inf;
//		for(int i=1;i<=n;i++)
//		{//到左面下降长度,包括自身
//			if(i>1&&a[i-1]<a[i])
//				cnt=0;
//			cnt++;
//			des[i]=cnt;
//		}
//		cnt=0;
//		for(int i=n;i>=1;i--)
//		{//到右面的最长上升长度,包括自身
//			if(i<n&&a[i]>a[i+1])
//				cnt=0;
//			cnt++;
//			inc[i]=cnt;
//		}
//		if(des[n]==n||inc[1]==n)
//			ok=1;
////		cout<<"des:"<<endl;
////		for(int i=1;i<=n;i++)
////			cout<<des[i]<<' ';
////		cout<<endl;
////		cout<<"inc:"<<endl;
////		for(int i=1;i<=n;i++)
////			cout<<inc[i]<<' ';
////		cout<<endl;
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i]<a[pos])
//				pos=i;
//			if(des[pos]>=pos&&inc[pos]>=i-pos+1)
//			{
//				if(i<n&&inc[i+1]>=n-i&&a[i]-a[pos]<=a[i+1])
//					ok=1;
//			}
//			if(ok)
//			{
//				printf("now=%d\n",i);
//				break;
//			}
//		}
		cout<<(ok?"YES":"NO")<<endl;
	}
	return 0;
}
/*
999
3
1 2 1
5
11 7 9 6 8
5
1 3 1 3 1
4
5 2 1 10
ans=y,y,n,y
999
5
1 2 3 4 5
5
5 4 3 2 1
5
4 3 2 1 8
4
8 1 2 3
3
2 1 2
7
11 6 7 10 9 9 8
ans=y,y,y,y,y
*/

