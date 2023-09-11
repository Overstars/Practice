#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=505,inf=0x3f3f3f3f,mod=1000000007;
//#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
char s[maxn][maxn];
int row[maxn],col[maxn];
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int w,h,tot=0;
	cin>>w>>h;
	for(int i=1;i<=w;i++)
	{
		for(int j=1;j<=h;j++)
		{
			cin>>s[i][j];
			if(s[i][j]=='*')
				row[i]++,col[j]++,tot++;
		}
	}
	bool ok=1;
	for(int i=1,st=0;i<=w;i++)
	{//五种状态
		if(row[i]==1)
		{
			if(st==0)
				st=1;
			else if(st==2)
				st=3;
		}
		else if(row[i]>1)
		{
			if(st!=1)
				ok=0;
		}
	}
	return 0;
}


