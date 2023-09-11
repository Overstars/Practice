 #include<stdio.h>
int main(void)
{
	int T,n,m;//T组数据，n门课，学m门
	scanf("%d",&T);
	while(T-->0){
		scanf("%d %d",&n,&m);
		int efficiency,a1,a2;//a1为当前课程难度，a2为下一课程难度 
		const initial=100;
		scanf("%d",&a1);
		while(n-->1){
			scanf("%d",&a2);
			if(a2<a1){
			a1=a2;
			}
		}
		efficiency=(initial-a1)*(initial-a1);
		printf("%d\n",efficiency);
	} 
	return 0;
}
