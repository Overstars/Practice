#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
char s[maxn][maxn];
int a[maxn][maxn],b[maxn][maxn];
int jud(int x,int y)
{
	int cnt=0;
	if(s[x][y]=='.'&&s[x+1][y]=='.')
		cnt++;
	if(s[x][y]=='.'&&s[x][y+1]=='.')
		cnt++;
//	if(a[x][y+1]-a[x-1][y+1]-a[x][y-1]+a[x-1][y-1])//横着
//		cnt++;
//	if(a[x+1][y]-a[x+1][y-1]-a[x-1][y]+a[x-1][y-1])
//		cnt++;
	return cnt;
}
int main()
{
	int h,w,q,x1,y1,x2,y2;
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;i++)
		scanf("%s",s[i]+1);
	for(int i=2;i<=h;i++)
		for(int j=1;j<=w;j++)
		{
			a[i][j]=a[i-1][j];//竖着
			if(s[i][j]=='.'&&s[i-1][j]=='.')
				a[i][j]++;
		}
	for(int i=1;i<=h;i++)
		for(int j=2;j<=w;j++)
		{
			b[i][j]=b[i][j-1];
			if(s[i][j]=='.'&&s[i][j-1]=='.')
				b[i][j]++;
		}
//	for(int i=1;i<=h;i++)
//		for(int j=1;j<=w;j++)
//			a[i][j]=a[i][j-1]+a[i-1][j]-a[i-1][j-1]+((s[i][j]=='.')?1:0);
	scanf("%d",&q);
//	for(int i=1;i<=h;i++)
//	{
//		for(int j=1;j<=w;j++)
//			printf("%d ",a[i][j]);
//		printf("\n");
//	}
	while(q--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int ans=0;
		for(int i=y1;i<=y2;i++)
			ans+=a[x2][i]-a[x1][i];
		for(int i=x1;i<=x2;i++)
			ans+=b[i][y2]-b[i][y1];
		printf("%d\n",ans);
	}
	return 0;
}
