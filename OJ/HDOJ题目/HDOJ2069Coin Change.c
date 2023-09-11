#include<stdio.h>
int coin[5]={50,25,10,5,1};
int main()
{
	int cent,ways,i,j,k,l,m;
	while(scanf("%d",&cent)==1){
		ways=0;
		for(i=0;i*coin[0]<=cent;i++){
			for(j=0;j*coin[1]<=cent-i*coin[0];j++){
				for(k=0;k*coin[2]<=cent-i*coin[0]-j*coin[1];k++){
					for(l=0;l*coin[3]<=cent-i*coin[0]-j*coin[1]-k*coin[2];l++){
						for(m=0;m*coin[4]<=cent-i*coin[0]-j*coin[1]-k*coin[2]-l*coin[3];m++)
							if(cent-i*coin[0]-j*coin[1]-k*coin[2]-l*coin[3]-m*coin[4]==0&&i+j+k+l+m<=100)
								ways++;
					}
				}
			}
		}
		printf("%d\n",ways);
	}
	return 0;
}
