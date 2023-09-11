//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
#define ff first
#define ss second
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
char s[maxn];
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
		cin>>n>>s+1;
		int now=1;
		vector<int>v;
		for(int i=2;i<=n;i++)
		{
			if(s[i]!=s[i-1])
			{
				v.push_back(now);
				now=0;
			}
			now++;
		}
		v.push_back(now);
//		vector<int>ret(v.size()+1,0);
//		for(int i=v.size()-1;i>=0;i--)
//		{//富裕后缀和
//			ret[i]=ret[i+1]+v[i]-1;
//		}
		int ans=0;
		for(int l=0,r=0;l<v.size();l++)
		{
			if(v[l]>=2)
			{//操作1,2都从这里删
				ans++;
			}
			else{//操作1要贪心从下面富裕的部分找
				while(r<v.size()&&v[r]==1)
					r++;
				if(r<v.size()&&v[r]>=2)
					v[r]--;
				else//从左面删
					l++;
				ans++;
			}
			if(r<=l)
				r=l+1;
		}
//		int cost=0,ans=v.size();
//		bool del=0;
//		for(int i=0;i<v.size();i++)
//		{
//			printf("x=%d,ret[%d]=%d,cost=%d,del=%d\n",v[i],i,ret[i],cost,del);
//			if(v[i]-2>=cost)
//			{//清空cost
//				cost=0;
//			}
//			else{
//				if(v[i]>2)//
//					cost-=v[i]-2;
//				else if(del)
//				{
//					ans--;
//					del=0;
//					continue;
//				}
//				else if(v[i]==1)
//				{
//					if(cost<ret[i])
//						cost++;
//					else
//						del=1;
//				}
//			}
//		}
//		cout<<"ans=";
		cout<<ans<<endl;
	}
	return 0;
}
/*
999
10
1110010111
6
111111
9
100100100
4
1001
ans=5,1,5,2
*/

