#include<stdio.h>
int main(void)
{
	int t,n,m;
	double y,p1,p2,a,b,ex;
	int arr1[1005],arr2[1005];
	scanf("%d",&t);
	while(t-->0){
		scanf("%d %d %lf",&n,&m,&y);
		int i;
		a=0,b=0,ex=0;
		for(i=0;i<n;i++){
			scanf("%d",&arr1[i]);
			a+=arr1[i];
		}
		a=a/n;
		for(i=0;i<m;i++){
			scanf("%d",&arr2[i]);
			b+=arr2[i];
		}
		b=b/m;
		p1=1.0*n/(n+m);
		p2=1.0*m/(n+m);
		double pp1=p1,pp2=p2;
		for(i=0;i<500;i++){
			ex+=pp1*a+pp2*b;
			pp1*=p2;
			pp2*=p2;
		}
		if(ex<=y)
			printf("Go\n");
		else
			printf("Wait\n");
	}
	return 0;
}
