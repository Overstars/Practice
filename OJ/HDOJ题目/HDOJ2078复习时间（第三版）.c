 #include<stdio.h>
int main(void)
{
	int T,n,m;//T�����ݣ�n�ſΣ�ѧm��
	scanf("%d",&T);
	while(T-->0){
		scanf("%d %d",&n,&m);
		int efficiency,a1,a2;//a1Ϊ��ǰ�γ��Ѷȣ�a2Ϊ��һ�γ��Ѷ� 
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
