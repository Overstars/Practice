#include<stdio.h>
#include<math.h>
int main(void)
{
	int n,m;
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&m);//����n����m�� 
		double N=n;
		double a=sqrt(N);
		while(m-->1){
			N=N+a;
			a=sqrt(a);
		} 
		printf("%.2f\n",N);
	}
	return 0;
}
