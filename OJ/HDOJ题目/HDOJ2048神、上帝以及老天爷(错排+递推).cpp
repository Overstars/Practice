//���n�������ΪF(n),��n-1��ΪF(n-1)
//1.����n��Ԫ�ط�������λ�ã�һ����n-1�֣�������ڵ�k��λ��
//2.���õ�k��Ԫ�أ������ֿ��ܣ�
//��k���ڵ�n��λ�ã�n����k��λ�ã�ʣ��n-2��Ԫ�ش��ţ�һ��F(n-1)�ֿ���
//��k�����ڵ�n��λ�ã�n-1��Ԫ�ش��ţ�һ��F(n-2)�ֿ���
//���ƹ�ʽF(n)=(n-1)*[F(n-2)+F(n-1)]
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	long long F[30]={0,0,1},all=2;//all��������ϵĿ��ܸ���
	double rate[30]={0,0,0.5};
	int i,t;
	for(i=3;i<22;i++){
		F[i]=(i-1)*(F[i-2]+F[i-1]);
		all*=i;
		rate[i]=(double)F[i]/all;
	}
	int c;
	cin>>c;
	while(c--){
		cin>>t;
		printf("%.2lf%%\n",rate[t]*100);
	}

	return 0;
}
