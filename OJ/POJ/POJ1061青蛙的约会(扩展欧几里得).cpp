#include<iostream>//�Ƽ���ƪhttps://blog.csdn.net/yoer77/article/details/69568676
#include<cstdio>//https://blog.csdn.net/baidu_33153085/article/details/52137179#commentBox
#include<algorithm>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y)
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
//ͨ��x = x0 + b/gcd(a,b)*t;//x0Ϊһ�ؽ�
//y = y0 - a/gcd(a,b)*t;
//(x0, y0 Ϊ���̵�һ���ؽ⣬ tΪ����)
int main()
{
	long long x,y,m,n,l;//ֻ��������
	while(cin>>x>>y>>m>>n>>l){
		if(m>n)
			swap(m,n),swap(x,y);
		long long r,s,t;//��s��,tȦ,����(n-m)s+lt=x-y
		r=exgcd(l,n-m,t,s);//s�ǿ��ܴ�
//		while(s>0||t<0){
//			printf("1.s=%d,t=%d\n",s,t);
//			s-=l/r;
//			t+=(n-m)/r;
//		}
//		while(s<0&&t>0){
//			printf("2.s=%d,t=%d\n",s,t);
//			s+=l/r;
//			t-=(n-m)/r;
//		}
//		printf("2.s=%d,t=%d\n",s,t);
		if((x-y)%r||m==n)
			cout<<"Impossible"<<endl;
		else{
			cout<<((s*(x-y)/r)%(l/r)+(l/r))%(l/r)<<endl;
		}//��С�����������֤��:https://www.cnblogs.com/hadilo/p/5914302.html���Ĳ���
	}
	return 0;
}
