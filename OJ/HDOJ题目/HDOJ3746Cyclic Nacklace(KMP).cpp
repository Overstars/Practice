#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[100005];
int nex[100005];
void getnex(int n)
{
	nex[0]=0;
	for(int i=1,j=0;i<n;i++){
//		j=nex[i-1];
		while(j>0&&s[i]!=s[j])
			j=nex[j-1];
		if(s[i]==s[j])
			j++;
		nex[i]=j;
	}
}
int main()//��˻��Ҷ���������ַ�,ʹ�ַ�����Ϊ�ظ���
{
	int t;
	cin>>t;
	while(t--){
		scanf("%s",s);
		int len=strlen(s);
		getnex(len);
		int l=len-nex[len-1];//nexΪ��󹫹��Ӵ�
		if(len%l==0&&l!=len)//l����Сѭ����
			printf("0\n");
		else if(l==len)//s����󹫹��Ӵ�=0,�����ظ�һ��
			printf("%d\n",len);//���Ժ�����ķ�֧�ϲ���
		else
			printf("%d\n",l-nex[len-1]%l);
	}
	return 0;
}
//lһֱΪ���ܵ���С�ظ���,��sȥ���˺�׺����󹫹��Ӵ�ʣ�µ���һ����
//��l>nexʱ,ans�൱�ڲ�����s��β��l-nex���ַ�
//l<nexʱ,����:abbabba,l=3,������С�ظ���abb
//�����Ե�����s=abababa,nex=5,l=2(����ab),��Ϊ��󹫹��Ӵ�nex����,����s��0��len-len%l��һ����,һֱ��ѭ��l����
//�ҽ�βʣ�µ�len%l���ַ�,Ҳ��l����ǰlen%l���ַ�
//����printf("%d\n",l-nex[len-1]%l);����l-len%lҲ���е�ͨ��
