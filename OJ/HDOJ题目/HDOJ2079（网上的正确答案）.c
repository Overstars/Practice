//ĸ�������
//�������⣺
//������m����ֵ��Ӳ�ң�ÿһ�ֵ���ֵΪa[i],����Ϊb[i]
//�����ж����ַ�������nԪǮ
#include<stdio.h>
#include<string.h>
 
int c1[1000],c2[1000];//c1[n]����nԪǮ�ж����ַ������ɡ�
int a[45],b[45];
 
int main()
{
	int t,i,j,k,n,m,sum;//t������ 
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d%d",&n,&m);//����nѧ�֣�һ����m�� 
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a[i],&b[i]);//ѧ��Ϊa�Ŀ���b�� ����a,b�����¼m�� 
			sum=sum+a[i]*b[i];//�����ܹ���ѧ�� 
		}
		for(i=0;i<=sum;i++)//��ʼ������,��������������? 
		{
			c1[i]=0;//c1����ÿһ��ϵ�� 
			c2[i]=0;//c2����ÿһ���� 
		}
		c1[0]=1;//
		for(i=1;i<=b[1];i++)
			c1[i*a[1]]=1;
		int len=a[1]*b[1];
		for(i=2;i<=m;i++)
		{
			for(j=0;j<=len;j++)
				for(k=0;k<=a[i]*b[i];k=k+a[i])
					c2[k+j]=c2[k+j]+c1[j];
			len=len+a[i]*b[i];
			for(j=0;j<=sum;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		printf("%d\n",c1[n]);//�����Ϊn��һ���ϵ�� 
	}
	return 0;
}
//--------------------- 
//���ߣ�xieshimao 
//��Դ��CSDN 
//ԭ�ģ�https://blog.csdn.net/xieshimao/article/details/6667942 
//�ο���https://blog.csdn.net/qq_41357771/article/details/83449481 
//��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
