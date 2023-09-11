#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int maxn=405<<1,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
char s[maxn];
int lr[maxn],lb[maxn],rr[maxn],rb[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n>>s+1;
	for(int i=1;i<=n;i++)
		s[n+i]=s[i];
	for(int i=1;i<=2*n;i++)
	{//向左取以第i位为结尾可以取的个数
		if(s[i]=='r')
			rr[i]=rr[i-1]+1;
		else if(s[i]=='b')
			rb[i]=rb[i-1]+1;
		else{
			rr[i]=rr[i-1]+1;
			rb[i]=rb[i-1]+1;
		}
//		printf("rr[%d]=%d,rb[%d]=%d\n",i,rr[i],i,rb[i]);
	}
	for(int i=2*n;i>=1;i--)
	{//向右取以第i位为结尾可取的个数
		if(s[i]=='r')
			lr[i]=lr[i+1]+1;
		else if(s[i]=='b')
			lb[i]=lb[i+1]+1;
		else{
			lr[i]=lr[i+1]+1;
			lb[i]=lb[i+1]+1;
		}
	}
	int ans=0;
	for(int i=0;i<=2*n;i++)
		ans=max(ans,max(rr[i],rb[i])+max(lr[i+1],lb[i+1]));
	cout<<min(ans,n)<<endl;
	return 0;
}


