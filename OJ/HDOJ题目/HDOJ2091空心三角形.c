//�ⲻ�ѣ������ʽ��Ѫ��һ��
#include<stdio.h>
int main(void)
{
	int n,i,j,flag=0;;
	char ch;
	while(scanf(" %c",&ch)==1&&ch!='@'){
		if(flag)
			putchar('\n');
		scanf("%d",&n);
		for(i=0;i<n-1;i++){
			for(j=0;j<n-i-1;j++)
				putchar(' ');
			putchar(ch);
			if(i>0){
				for(j=0;j<2*i-1;j++)
					putchar(' ');
				putchar(ch);
			}
			putchar('\n');
		}
		for(i=0;i<2*n-1;i++)//��
			putchar(ch);
		putchar('\n');
		flag=1;
	}
	return 0;
}
