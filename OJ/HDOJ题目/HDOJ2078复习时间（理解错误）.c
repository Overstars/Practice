#include<stdio.h>
int main(void)
{
	int T,n,m,efficiency;//T�����ݣ�n�ſΣ����ѧm��
	scanf("%d",&T);
	while(T-->0){
		int a[39],i,min,c;//minΪ��������С�� 
		for(i=0;i<40;i++)
		scanf("%d",&a[i]);
		min=a[0];
		int b;
		for(b=0;b<40;b++){
			if(min>a[b])
			min=a[b];
		}
		efficiency=(100-a[1])*(100-a[1]);
		c=(a[1]-min)*(a[1]-min);
		if(efficiency<c)
		efficiency=c;
		printf("%d",efficiency);
	}
	return 0;
 } 
