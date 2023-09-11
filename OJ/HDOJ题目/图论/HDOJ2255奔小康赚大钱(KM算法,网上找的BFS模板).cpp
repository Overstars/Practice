//#pragma G++ optimize("O2")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iomanip>//控制输出,<<setiosflags(ios::fixed)<<setprecision(9)
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>
using namespace std;
const int maxn = 305;
const int INF=0x3f3f3f3f;
int w[maxn][maxn];//二分图间的权值
int lx[maxn],ly[maxn];
int linker[maxn];//B图匹配到的A图节点
int slack[maxn];
int n;
bool visy[maxn];//记录每一轮B图匹配过
int pre[maxn];
void bfs( int k )
{
    int x,y=0,yy=0,delta;
    memset(pre,0,sizeof(pre));
    for( int i = 1 ; i <= n ; i++ )
		slack[i] = INF;
    linker[y] = k;
    while(1)
	{
        x = linker[y];
        delta = INF;
        visy[y] = true;
        for( int i = 1 ; i <= n ;i++ )
		{
            if( !visy[i] )
            {
                if( slack[i] > lx[x] + ly[i] - w[x][i] )
                {
                    slack[i] = lx[x] + ly[i] - w[x][i];
                    pre[i] = y;
                }
                if( slack[i] < delta )
					delta = slack[i] , yy = i ;
            }
        }
        for( int i = 0 ; i <= n ; i++ )
        {
            if( visy[i] )
				lx[linker[i]] -= delta , ly[i] += delta;
            else
				slack[i] -= delta;
        }
        y = yy ;
        if( linker[y] == -1 )
			break;
    }
    while( y )
		linker[y] = linker[pre[y]] , y = pre[y];
}
int KM()
{
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    memset(linker,-1,sizeof(linker));
    for(int i=1;i<=n;i++)
	{
        memset( visy , false , sizeof(visy));
        bfs(i);
    }
    int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(linker[i]!=-1)
			ans+=w[linker[i]][i];
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&w[i][j]);
		printf("%d\n",KM());
	}
	return 0;
}
