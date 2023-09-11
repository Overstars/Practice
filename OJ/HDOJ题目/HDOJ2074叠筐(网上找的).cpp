#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
char a[100][100];
/*
思路：
画1层
@@@@@
@   @
@   @
@   @
@@@@@
画2层
@@@@@
@WWW@
@W W@
@WWW@
@@@@@
3层
@@@@@
@WWW@
@W@W@
@WWW@
@@@@@
去角：
 @@@
@WWW@
@W@W@
@WWW@
 @@@
OK

*/


int main()
{
	int n,i,j,k,flag=0;
	char side,in,m;
	while(~scanf("%d %c %c",&n,&in,&side))
	{
		if(flag)//格式：每个之间，最后一个和第一个不需要空行！
		{
			printf("\n");
		}
		flag=1;
		if(n==1)//1直接输出内层图案
		{
			printf("%c\n",in);
			continue;
		}
		memset(a,'\0',sizeof(a));
		i=0;//第一行
		j=0;//第一列
		k=0;//从最外层开始
		if((n/2+1)%2==0)//判断最外层是什么图案
		m=side;
		else
		m=in;
		while(1)
		{
			for(;j<n-k;j++)//第k层的上面一行
			{
				a[i][j]=m;
			}
			j--;//回到正确的列数
			for(;i<n-k;i++)//右边的那一列
			{
				a[i][j]=m;
			}
			i--;//回到正确的列数
			for(;j>=k;j--)//下面的一行
			{
				a[i][j]=m;
			 }
			 j++;
			 for(;i>=k;i--)//左边的一列
			 {
			 	a[i][j]=m;
			 }
			 i=i+2;//先恢复，然后往下走一，层
			 j+=1;//列数同理
			 if(m==side)//每画一层更换符号
			 {
			 	m=in;
			 }
			 else
			 {
			 	m=side;
			 }
			 k++;
			 if(k==n/2+1)//最后一层
			 break;
		}
		a[0][0]=' ';//更换四个角
		a[0][n-1]=' ';
		a[n -1][0]=' ';
		a[n-1][n-1]=' ';
		for(i=0;i<n;i++)
		{
			puts(a[i]);
		}
	}
 }
