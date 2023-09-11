/*A+B for Input-Output Practice (II)
*46秒看题，1分15秒敲代码，13秒提交*/
#include<stdio.h>
int main(void)
{
	int N,a,b;
	scanf("%d",&N);
	while(N-->0){
		scanf("%d %d",&a,&b);
		printf("%d\n",a+b);
	}
	return 0;
}
