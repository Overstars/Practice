#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=505,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int dp[maxn][maxn],f[maxn];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>dp[i][i];
	for(int len=2;len<=n;len++)//长度
	{
		for(int l=1;l<=n;l++)//起点
		{
			int r=l+len-1;//终点
			if(r>n)
				break;
			for(int k=l;k<r;k++)//枚举分割点
			{
				if(dp[l][k]&&dp[l][k]==dp[k+1][r])
					dp[l][r]=dp[l][k]+1;
			}
		}
	}
	memset(f,inf,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			if(dp[j+1][i])//j+1到i可以合成一块
				f[i]=min(f[i],f[j]+1);
	cout<<f[n]<<endl;
	return 0;
}


