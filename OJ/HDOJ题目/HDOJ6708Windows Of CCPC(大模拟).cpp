#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f;
char s[11][1<<11][1<<11];
int main()
{
	memset(s,0,sizeof(s));
	s[1][0][0]=s[1][0][1]=s[1][1][1]='C',s[1][1][0]='P';
	for(int i=2;i<11;i++)
	{
		int row=1<<i,col=1<<i,pre=1<<(i-1);
		for(int j=0;j<pre;j++)//对列操作
		{
			int c=j<<1;
			for(int k=0;k<pre;k++)//对行操作
			{
				int r=k<<1;
				if(s[i-1][j][k]=='C')
				{
					s[i][c][r]=s[i][c][r+1]=s[i][c+1][r+1]='C';
					s[i][c+1][r]='P';
				}
				else{
					s[i][c][r]=s[i][c][r+1]=s[i][c+1][r+1]='P';
					s[i][c+1][r]='C';
				}
			}
		}
	}
	int t,k;
	cin>>t;
	while(t--){
		cin>>k;
		int len=1<<k;
		for(int i=0;i<len;i++)
			puts(s[k][i]);
	}
	return 0;
}
