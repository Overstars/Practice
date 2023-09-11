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
bool vis[1<<13];
int ans[1<<13];
void dfs(int x)
{
	if(vis[x])
		return;
	vis[x]=1;
	int cnt=0;
	for(int i=1;i<=(1<<11);i<<=1)
		if(x&i)
			cnt++;
	ans[x]=cnt;
	for(int i=3,t1=1,t2=2,t3=4;i<=12;i++,t1<<=1,t2<<=1,t3<<=1)
	{//分别为这三个位的状态
		if((x&t2)&&!((x&t1)&&(x&t3))&&((x&t1)||(x&t3)))
		{
			if(x&t1)
			{
				dfs(x-t2-t1+t3);
				ans[x]=min(ans[x],ans[x-t2-t1+t3]);
			}
			else{
				dfs(x-t2-t3+t1);
				ans[x]=min(ans[x],ans[x-t2-t3+t1]);
			}
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	for(int i=0;i<(1<<12);i++)//预处理
		dfs(i);
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int now=0;
		for(auto &ch:s)
		{
			now<<=1;
			if(ch=='o')
				now|=1;
		}
		cout<<ans[now]<<endl;
	}
	return 0;
}


