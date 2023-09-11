#include<stdio.h>
int main(void)
{
	int m;
	scanf("%d",&m);//一共有m个方程 
	for(m;m>0;m--)
	func();
	return 0;
}

int func(void)
{
	float s=0.0;
	int n;
	scanf("%d",&n);//这个方程有n项 
	while(n>0){
		if(n%2==1)//n为奇数项 
		s=s+(double)1/n;
		else//n为偶数项 
		s=s-(double)1/n;
		n--;//从后向前推 
	}
	printf("%.2f\n",s);
	return 0;
}
