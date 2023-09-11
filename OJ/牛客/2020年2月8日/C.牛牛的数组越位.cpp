#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005,inf=0x3f3f3f3f,mod=1000000007;
//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
template<class T>inline void read(T &x) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
}
int a[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m,q,x,y,val;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(register int i=0;i<n;i++)
			for(register int j=0;j<m;j++)
				a[i][j]=0;
//		cin>>n>>m>>q;
		int flag=0;//越界1,非法2
		while(q--)
		{
			scanf("%d%d%d",&x,&y,&val);
			if(flag==2)
				continue;
			if(x>=n||y>=m||x<0||y<0)//越界行为
				flag=1;
			int no=m*x+y;//真实访问地址
			if(no<0||no>=n*m)//非法访问
			{
				flag=2;
				continue;
			}
			int nx=no/m,ny=no%m;
			a[nx][ny]=val;
		}
		if(flag==2)
			puts("Runtime error");
		else{
			for(register int i=0;i<n;i++)
				for(register int j=0;j<m;j++)
					printf("%d%c",a[i][j],(j==m-1)?'\n':' ');
		}
		if(flag==1)
			puts("Undefined Behaviour");
		else if(flag==0)
			puts("Accepted");
	}
	return 0;
}


