#include<stdio.h>
int a[200010]={0};
int b[1000000][2];
int main(void)
{
	int n,m,p;//nΪ����վ����mΪѯ�ʴ��� 
	int x,y,i=0,sum=0;
	
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);//a[i]Ϊ��i+1����һվ��ʱ�� 
	for(i=0;i<n;i++)
		sum+=a[i];
	p=m;
	for(i=0;p-->0;i++)
		scanf("%d %d",&b[i][0],&b[i][1]);
	
		int j=0;
		while(m-->0){
			int d,time1=0,time2=0,time=0;
	//		scanf("%d %d",&x,&y);//�Ҿ����б�Ҫ�Ƚ���x,y�Ĵ�С 
			x=b[j][0];
			y=b[j][1];
			if(x>y){
				d=y;
				y=x;
				x=d;
			}
			for(x=x-1;x<y-1;x++){
				time1+=a[x];
			}
			time2=sum-time1;
			time=(time1<time2)?time1:time2;
			printf("%d\n",time);
			j++;
	}
	return 0;
}
