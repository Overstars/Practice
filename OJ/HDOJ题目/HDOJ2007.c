#include<stdio.h>
int main(void)
{
	int x,y,z;
	while(scanf("%d %d",&x,&y)!=EOF){
		if(x>y){
			z=y;//Сֵ�����м��� 
			y=x;//��ֵ����y 
			x=z;//Сֵ����x 
		}
		 
		long int squ=0,cube=0;
		for(x;x<=y;x++){
			if(x%2==0)
			squ+=x*x;
			else
			cube+=x*x*x;
		}
		printf("%ld %ld\n",squ,cube);
	}
	return 0;
}
