#include<stdio.h>
#include<string.h>
int main(void)
{
	int i,j,t,n,m,x,k,stu[10005],school[2][1005],std,count,count2,sum;
	scanf("%d",&t);
	while(t-->0){
		memset(stu,0,sizeof(int));
		memset(school,0,sizeof(int));
		scanf("%d %d %d",&n,&m,&k);
		std=n/2;
		for(i=1;i<=n;i++){
			scanf("%d",&stu[i]);//�����i��ѧ��ѧУ 
		}
		for(i=1;i<=m;i++){
			count=0,count2=0;
			for(j=1;j<=n;j++){
				if(stu[j]==i){
					count++;
					if(j<=std)
						count2++;
				}	
			}
			school[1][i]=count;//��ѧУ����������
			school[0][i]=count2;//��ѧУǰ50%������ 
		}
		sum=0; 
		for(i=1;i<=m;i++){
			if(school[0][i]<=school[1][i]/k)
				sum+=school[0][i];
			else
				sum+=school[1][i]/k;
		}
		printf("%d\n",sum);
	}
	return 0;
}
