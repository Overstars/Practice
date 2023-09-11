#include<stdio.h>
#include<string.h>
int min(int a,int b);
int minest(int a,int b,int c);
int boy[1005],girl[1005],cp[1005];
int main(void)
{
	int i,t,n,m,k,a,b,c;
	scanf("%d",&t);
	while(t-->0){
		memset(boy,0,sizeof(int));
		memset(girl,0,sizeof(int));
		memset(cp,0,sizeof(int));
		scanf("%d %d %d",&n,&m,&k);
		for(i=1;i<3;i++)
		{
			boy[i]=min(a,b);
			girl[i]=min(a,b);
		}
		boy[3]=min(2*a,b);
		boy[3]=min(2*a,b);
		cp[1]=minest(2*a,2*b,c);
		cp[2]=minest(2*a,2*b,2*c);
		cp[3]=minest(3*a,2*b,3*c);
		for(i=4;i<=n;i++){
			boy[n]=min(boy[n-2]+a,boy[n-3]+b);
			girl[m]=min(girl[m-2]+a,girl[m-3]+b);
			cp[k]=minest(cp[k-2]+2*a,cp[k-3]+3*b,cp[k-1]+c);//这么些明摆着就过不了，不能把cp分开考虑 
		}
		printf("%d",boy[n]+girl[m]+cp[k]);
	}
	return 0;
}
int min(int a,int b)
{
	return (a>b)?b:a;
}
int minest(int a,int b,int c)
{
	int min=a;
	if(b<min)
		min=b;
	if(c<min)
		min=c;
	return min;
}
