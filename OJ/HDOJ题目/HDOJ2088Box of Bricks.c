#include<stdio.h>
int main(void)
{
	int n,h[105],flag=0;
	while(scanf("%d",&n)==1&&n){
		if(flag) putchar('\n');
		flag=1;
		int i,sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&h[i]);
			sum+=h[i];
		}
		double aver=(double)sum/n,ans=0;
		for(i=0;i<n;i++){
			if(h[i]>aver)
				ans+=h[i]-aver;
		}
		printf("%.0lf\n",ans);
	}
	return 0;
}
