#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,temp,jud=0;
	while(scanf("%d",&n)==1&&n){
		jud=0;
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			jud^=temp;
		}
		printf("%d\n",jud);
	}
	return 0;
}
