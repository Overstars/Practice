#include<stdio.h>
int main(void)
{
	int T,n,m;//T�����ݣ�n�ſΣ�ѧm��
	scanf("%d",&T);
	while(T-->0){
		scanf("%d %d",&n,&m);
		int efficiency,eff2,a1,a2;//a1Ϊ��ǰ�γ��Ѷȣ�a2Ϊ��һ�γ��Ѷ� 
		const initial=100;
		scanf("%d",&a1);
		efficiency=(initial-a1)*(initial-a1);
		while(n-->1&&m>1){
			scanf("%d",&a2);
			if(a2<a1){
			eff2=(a1-a2)*(a1-a2);
			m--;
			a1=a2;
			}
			if(eff2>efficiency)
			efficiency=eff2;
		}
		printf("%d",efficiency);
	} 
	return 0;
}
