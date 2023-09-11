#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
//#define int ll
const int maxn=2e5+10,inf=0x3f3f3f3f,mod=1000000007;
#define DEBUG//#define lowbit(x) ((x) & -(x))//<<setiosflags(ios::fixed)<<setprecision(9)
void read(){}
template<typename T,typename... T2>inline void read(T &x,T2 &... oth) {
	x=0; int ch=getchar(),f=0;
	while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(f)x=-x;
	read(oth...);
}
int week(int y,int m,int d)
{
	 if(m==1||m==2) m+=12,y=y-1;
	return (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7;
}
signed main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
//		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif
	for(int i=2000;i<=2100;i++)
	{
		if(i>2000)
			printf(",");
		int cnt=0;
		for(int j=1;j<=31;j++)
		{
			if(week(i,5,j)==0)
			{
				cnt++;
				if(cnt==2)
				{
					printf("%d",j);
					break;
				}
			}
		}
	}
	return 0;
}


