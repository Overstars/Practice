#include<iostream>
using namespace std;
int main(void)
{
	long long st[40]={0,2,8},i,n;
	for(i=3;i<37;i++){
		st[i]=3*st[i-1]+2;
	}
	while(cin>>n)
		cout<<st[n]<<endl;
	return 0;
}
//woc,�����Ҿ�Ȼ������������
//һ��n�㣬�Ƚ�����n-1���Ƶ�����,�ٽ���n����������
//�ٽ�������n-1���Ƶ��������ٽ������ĵ�n����������,������n-1��Ҳ��������
//���ƹ�ʽst[i]=3*st[i-1]+2;
//�ðɣ�ȷʵ����(�� �㧥 ��;)��
