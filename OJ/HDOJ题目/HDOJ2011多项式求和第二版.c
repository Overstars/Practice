#include<stdio.h>
int main(void)
{
	int m;
	scanf("%d",&m);//һ����m������ 
	for(m;m>0;m--)
	func();
	return 0;
}

int func(void)
{
	float s=0.0;
	int n;
	scanf("%d",&n);//���������n�� 
	while(n>0){
		if(n%2==1)//nΪ������ 
		s=s+(double)1/n;
		else//nΪż���� 
		s=s-(double)1/n;
		n--;//�Ӻ���ǰ�� 
	}
	printf("%.2f\n",s);
	return 0;
}
