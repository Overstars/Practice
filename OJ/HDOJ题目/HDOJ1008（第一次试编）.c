#include<stdio.h>
int main(void)
{
	int n; 
	scanf("%d",&n);
	while(n>0)
	{
		int a=0,b=1,c=0,d=n,e=n,time=0;
		int i[n];
		for(a;a<=n;a++)
		i[a]=0;//��ʼ��i[0]��i[n] 
		i[0]=0;//Ϊi[0]��ֵ�����ڽ���ѭ�� 
		while(--d>=0){
			scanf("%d",&i[b++]);
		} //Ϊ i[1]��i[n]��ֵ 
		while(c<e)
		{
			if(i[c]<i[c+1])
			{
				time=time+(i[c+1]-i[c])*6+5;//Ӧ�ò�����������ͬ��¥��ɣ� 
				c++;
			 } 
			else
			{
				time=time+(i[c]-i[c+1])*4+5;
				c++;
			}
		}
		printf("%d\n",time);
		scanf("%d",&n);
	}
	return 0;
}
