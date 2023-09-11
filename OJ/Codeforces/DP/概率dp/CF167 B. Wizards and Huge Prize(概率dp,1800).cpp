//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
typedef pair<int,int>pii;
#define ff first
#define ss second
#define debug(x) std:: cerr << #x << " = " << x << std::endl;
const int maxn=205,inf=0x3f3f3f3f,mod=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
double dp[maxn][maxn][maxn];//dp[i]表示到i个.
signed main(signed argc, char const *argv[])
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n,l,k,st=200;//胜过l轮,口袋初始容积k
	cin>>n>>l>>k;
	vector<pair<int,double>>pid(n);
	for(auto &i:pid)
	{
		cin>>i.ss;
		i.ss/=100;
//		cerr<<"i.ss = "<<i.ss<<endl;
	}
	for(auto &i:pid)
		cin>>i.ff;
	sort(pid.begin(),pid.end(),[](const pair<int,double> &a,const pair<int,double> &b){
			return a.ff>b.ff;
		});
	double ans=0;
	dp[0][0][min(k,n)]=1;
	for(int i=1;i<=n;i++)
	{
		int val=pid[i-1].ff;
		double p=pid[i-1].ss;
////		cerr<<"i.ss = "<<pid[i-1].ss<<endl;
//		printf("val = %d,p = %.6f\n",val,p);
		for(int j=0;j<i;j++)
		{
			for(int k=0;k<=n;k++)
			{
				if(k+val>=0)
				{//赢了
					dp[i][j+1][min(k+val,n)]+=dp[i-1][j][k]*p;
				}
				dp[i][j][k]+=dp[i-1][j][k]*(1-p);//输了,因为最后价值都为-,小于零不会再上来
			}
		}
	}
	for(int j=l;j<=n;j++)
		for(int k=0;k<=n;k++)
			ans+=dp[n][j][k];
	cout<<setiosflags(ios::fixed)<<setprecision(9)<<ans<<endl;
	return 0;
}
/*
 * 2021-05-06-18.08.14
 * 初始价值k
 * 1.每一轮有p的概率价值增加a
 * 2.有p的概率使价值减少1
 * dp[i][j][k]表示前i项获胜了j项,价值为k的概率
 * 如果中间背包容量>n了那么限制在n就好,多了也没用
*/

