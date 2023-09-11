#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int ans=0,n,rec[15];
bool vis[15],mp[40],mp2[40];
void dfs(int r,int x)//r行x列
{
	rec[r]=x;
	if(r==n)
	{
		ans++;
		if(ans<=3)
		{
			for(register int i=1;i<=n;i++)
				printf("%d ",rec[i]);
			putchar('\n');
		}
		return;
	}
	for(register int i=1;i<=n;i++)//第i列
	{//(r+1,i)同一列
		if(!vis[i]&&!mp[r+1+i]&&!mp2[20+r+1-i])
		{
			vis[i]=1;
			mp[r+1+i]=1;
			mp2[20+r+1-i]=1;
			dfs(r+1,i);
			vis[i]=0;
			mp[r+1+i]=0;
			mp2[20+r+1-i]=0;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	read(n);
	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}


