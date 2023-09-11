#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=16,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
ll a[maxn][maxn];
int n,m;
ll get(int x,int flag)
{
	ll ret=0;
	if(flag==1)
	{//得到一行
		for(int i=1;i<=m;i++)
			ret+=a[x][i];
	}
	else if(flag==2)
	{//得到一列
		for(int i=1;i<=n;i++)
			ret+=a[i][x];
	}
	else if(flag==3)
	{
		for(int i=1;i<=m;i++)
			a[x][i]=0;
	}
	else{
		for(int i=1;i<=n;i++)
			a[i][x]=0;
	}
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	ll ans=0;
	while(k--)
	{
		int rec=0,flag=0;
		ll sum=0;
		for(int i=1;i<=n;i++)
		{//得到一行
			ll now=get(i,1);
			if(now>sum)
			{
				sum=now;
				rec=i,flag=1;
			}
		}
		for(int i=1;i<=m;i++)
		{//得到一列
			ll now=get(i,2);
			if(now>sum)
			{
				sum=now;
				rec=i,flag=2;
			}
		}
		ans+=sum;
		if(flag==1)
			get(rec,3);
		else if(flag==2)
			get(rec,4);
		else
			break;
	}
	cout<<ans<<endl;
	return 0;
}


