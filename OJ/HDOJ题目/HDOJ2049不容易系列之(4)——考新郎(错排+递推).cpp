//���ţ�2048����
//һ����N�ԣ�ѡ��M�Խ��д��ţ�һ����C(N,M)��ѡ��
//�ô��ŵĵ��ƹ�ʽF(n)=(n-1)*[F(n-2)+F(n-1)]�����������Ϊ��
#include<iostream>
#include<cstdio>
using namespace std;
long long fun(long long n,long long m);
int main()
{
	long long F[25]={0,0,1},i;
	for(i=3;i<22;i++){
		F[i]=(i-1)*(F[i-2]+F[i-1]);
	}
	int C,n,m;
	cin>>C;
	while(C--){
		cin>>n>>m;
		cout<<fun(n,m)*F[m]<<endl;
	}
	return 0;
}
long long fun(long long n,long long m)
{
	long long a=1,b=1,c=1,i;
	for(i=1;i<=n;i++){
		a*=i;
	}
	for(i=1;i<=m;i++){
		b*=i;
	}
	for(i=1;i<=n-m;i++){
		c*=i;
	}
	return a/(b*c);
}
