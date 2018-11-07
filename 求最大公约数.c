#include<stdio.h> 
int main()
{
	int m,n,i;
	scanf("%d",&m);
	scanf("%d",&n);
	for(i=m;i>=1;i--)
	    if(m%i==0 && n%i==0)
	        break;
	printf("%d\n",i);
	system("PAUSE");
	return 0;
}
