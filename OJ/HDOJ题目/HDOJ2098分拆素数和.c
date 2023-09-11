#include<stdio.h>
#include<math.h>
int std[5005];
int main(void)
{
	int i,cnt=0;
	for(i=2;i<5003;i++){
		if(isprime(i))
			std[cnt++]=i;
	}
	int m;
	cnt=0;
	while(scanf("%d",&m)&&m){
		cnt=0;
		for(i=0;std[i]<m/2;i++){
			if(isprime(m-std[i])&&std[i]!=m-std[i])
				cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
int isprime(int x)
{
	int i;
	for(i=2;i<=sqrt(x);i++){
		if(x%i==0)
			return 0;
	}
	return 1;
}
