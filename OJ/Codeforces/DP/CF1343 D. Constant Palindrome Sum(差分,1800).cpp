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
int a[maxn],cost[maxn<<1];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		memset(cost,0,sizeof(cost));
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n/2;i++)
		{
			int x=a[i],y=a[n-i+1];
			if(x>y)
				swap(x,y);
			cost[2]+=2;//[2,x] [y+k+1,2*k]
			cost[x+1]-=2;
			cost[y+k+1]+=2;
			cost[2*k+1]-=2;//范围内修改两个

			cost[x+y]-=1;//[x+y]不必修改
			cost[x+y+1]+=1;

			cost[x+1]+=1;//标杆值在[x+1,x+k][y+1,y+k]范围只消耗一个
//			cost[x+k+1]-=1;//本题内x+k>=y+1
//			cost[y+1]+=1;
			cost[y+k+1]-=1;
		}
		int ans=inf,now=0;
		for(int i=2;i<=k*2;i++)
		{
			now+=cost[i];
			ans=min(ans,now);
		}
		cout<<ans<<endl;
	}
	return 0;
}


