#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
char a[100][100];
/*
˼·��
��1��
@@@@@
@   @
@   @
@   @
@@@@@
��2��
@@@@@
@WWW@
@W W@
@WWW@
@@@@@
3��
@@@@@
@WWW@
@W@W@
@WWW@
@@@@@
ȥ�ǣ�
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
		if(flag)//��ʽ��ÿ��֮�䣬���һ���͵�һ������Ҫ���У�
		{
			printf("\n");
		}
		flag=1;
		if(n==1)//1ֱ������ڲ�ͼ��
		{
			printf("%c\n",in);
			continue;
		}
		memset(a,'\0',sizeof(a));
		i=0;//��һ��
		j=0;//��һ��
		k=0;//������㿪ʼ
		if((n/2+1)%2==0)//�ж��������ʲôͼ��
		m=side;
		else
		m=in;
		while(1)
		{
			for(;j<n-k;j++)//��k�������һ��
			{
				a[i][j]=m;
			}
			j--;//�ص���ȷ������
			for(;i<n-k;i++)//�ұߵ���һ��
			{
				a[i][j]=m;
			}
			i--;//�ص���ȷ������
			for(;j>=k;j--)//�����һ��
			{
				a[i][j]=m;
			 }
			 j++;
			 for(;i>=k;i--)//��ߵ�һ��
			 {
			 	a[i][j]=m;
			 }
			 i=i+2;//�Ȼָ���Ȼ��������һ����
			 j+=1;//����ͬ��
			 if(m==side)//ÿ��һ���������
			 {
			 	m=in;
			 }
			 else
			 {
			 	m=side;
			 }
			 k++;
			 if(k==n/2+1)//���һ��
			 break;
		}
		a[0][0]=' ';//�����ĸ���
		a[0][n-1]=' ';
		a[n -1][0]=' ';
		a[n-1][n-1]=' ';
		for(i=0;i<n;i++)
		{
			puts(a[i]);
		}
	}
 }
