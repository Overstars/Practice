#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool jud(int n);
int p(int a,int b);
int main()
{
	int n;
	while(cin>>n)
		cout<<jud(n)<<endl;
}
bool jud(int n)//��Ҫ�жϵ�������
{
	int temp,head,tail,cnt=0,i;
	while(n>=10){//��nֻ��һλ,�����ж�
		tail=n%10;
		n/=10;//ȥ��λһλ
		temp=n;
		cnt=0;
		while(temp>=10){
			cnt++;
			temp/=10;//n��ʱΪcnt+1λ,tempΪ��һλ
		}
		head=temp;
		if(head!=tail)
			return 0;
		n%=p(10,cnt);//ȥ��ͷһλ
	}
	return 1;
}
int p(int a,int b)//a��b����
{
	int sum = 1;
	while(b>0) {
		if(b%2==1)
			sum=sum*a;
		b/=2;
		a=a*a;
	}
	return sum;
}
