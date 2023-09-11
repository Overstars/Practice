#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=505,inf=0x3f3f3f3f,mod=1000000007;
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
//#define DEBUG//<<setiosflags(ios::fixed)<<setprecision(9)
ll x[maxn],y[maxn],rec[4],ans=0;
ll e(int a,int b)
{
	ll dx=x[a]-x[b],dy=y[a]-y[b];
	return dx*dx+dy*dy;
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
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&y[i]);
//		cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				rec[0]=e(i,j);
				rec[1]=e(j,k);
				rec[2]=e(i,k);
//				printf("%lld,%lld,%lld\n",rec[0],rec[1],rec[2]);
				sort(rec,rec+3);
				if((y[k]-y[i])*(x[j]-x[i])-(y[j]-y[i])*(x[k]-x[i])!=0&&rec[0]+rec[1]<rec[2])
					ans++;
			}
		}
	}
	printf("%lld\n",ans);
//	cout<<ans<<endl;
	return 0;
}


