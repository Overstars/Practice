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
struct node
{
	int a,b,x;
};
int a[maxn];
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
		int sum=0,st;
		for(int i=1;i<=n;i++)
			cin>>a[i],sum+=a[i];
		if(sum%n)
		{
			cout<<-1<<endl;
			continue;
		}
		vector<node>ans;
		st=sum/n;
		for(int i=2;i<=n;i++)
		{
			int need=a[i]%i;
			if(need)
				need=i-need;
			if(need>0&&need<=a[1])
			{
				a[1]-=need;
				a[i]+=need;
				ans.push_back({1,i,need});
			}
			int x=a[i]/i;
			a[1]+=x*i;
			a[i]-=x*i;
			if(x>0)
				ans.push_back({i,1,x});
//				cout<<i<<' '<<1<<x<<endl;
		}
		for(int i=2;i<=n;i++)
		{
			if(a[i]<st)
			{
				ans.push_back({1,i,st-a[i]});
//				cout<<1<<' '<<i<<st-a[i];
				a[1]-=st-a[i];
				a[i]+=st-a[i];
			}
		}
		cout<<ans.size()<<endl;
		for(auto &i:ans)
			cout<<i.a<<' '<<i.b<<' '<<i.x<<endl;
//		cout<<endl;
//		cout<<"!!!"<<endl;
//		for(int i=1;i<=n;i++)
//			cout<<a[i]<<' ';
//		cout<<endl;
//		printf("st=%d\n",st);
	}
	return 0;
}
/*

*/
/*
 *总和不被n整除时,必定无解
 *把[2,n]位的数尽量移到1上
 *再总体从1分配(n步)
*/

