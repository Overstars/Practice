#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
long long llpow(long long a,long long b)//��������
{
	long long ans=1;
	while(b>0){
		if(b%2==1)
			ans*=a;
		a*=a;
		b/=2;
	}
	return ans;
}
long long exgcd(long long a,long long b,long long &x,long long &y)//��չŷ�����,Ҫ��֤a>b
{//����x,y������
    if(b == 0)
    {//����1����ֹ����
        x = 1;
        y = 0;
        return a;//�ҵ�gcd,һ·������ȥ
    }
    long long r = exgcd(b, a%b, x, y);
    //�ȵõ����ײ��x2,y2,�ٸ��ݼ���õ�x2,y2����x1��y1��
    //����2�����ƹ�ϵx1=y2,y1=x2-(a/b)*y2;
    long long t = y;
    y = x - (a/b) * y;//(a/b)����ȡ��
    x = t;
//    printf("x1=%d,y1=%d,r=%d\n",x,y,r);
    return r;
}
int main()
{
	long long a,b,c,k;//����Ϊa+cx=b%mod,xΪ���ܽ�
	while(cin>>a>>b>>c>>k&&(a||b||c||k)){
		long long mod=llpow(2,k),x,y;//ת��Ϊcx+mody=b-a,�����ʽ���
		long long r=exgcd(mod,c,y,x);
		if((b-a)%r)
			cout<<"FOREVER"<<endl;
		else
			cout<<((b-a)/r*x%(mod/r)+mod/r)%(mod/r)<<endl;
	}
	return 0;
}
