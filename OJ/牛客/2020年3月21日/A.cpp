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
struct node
{
	int x,y;
	node(int x=0,int y=0):
		x(x),y(y){}
};
char s[22][maxn];
ll cnt[maxn];
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	#ifdef DEBUG
		freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	#endif
	int t,n,m,a,b;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>a>>b;
		for(int i=1;i<=n;i++)
			cin>>s[i]+1;
		bool flag=0;
		for(int i=0;i<(1<<n);i++)
		{//枚举选了哪a行
			if(__builtin_popcount(i)!=a)
				continue;
			int tot=0;//有敌人的列
			for(int j=1;j<=m;j++)
			{//第j列是否有残余敌人
				for(int k=1;k<=n;k++)
				{
					if(((1<<(k-1)))&i)//这一行被消灭
						continue;
					if(s[k][j]=='*')
					{
						tot++;
						if(tot>b)
							goto label;
//						break;//少打break改了一年
					}
				}
			}
			label:
			if(tot<=b)
			{
				flag=1;
				break;
			}
		}
		cout<<(flag?"yes":"no")<<endl;
	}
	return 0;
}
/*
999
2 2 0 0
..
..
2 3 0 2
.*.*
.*.*
2 3 2 0
**.*
*.*.
3 3 1 2
***
*.*
*.*
2 4 1 2
.*.*
*.*.
3 3 2 2
****
*.*.
.*.*
3 3 2 2
****
*.*.
****
4 4 3 2
***.
.***
.*.*
*.*.
*/

