#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
long long llpow(long long a,long long b)//快速求幂
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
long long exgcd(long long a,long long b,long long &x,long long &y)//扩展欧几里得,要保证a>b
{//传递x,y的引用
    if(b == 0)
    {//推理1，终止条件
        x = 1;
        y = 0;
        return a;//找到gcd,一路返回上去
    }
    long long r = exgcd(b, a%b, x, y);
    //先得到更底层的x2,y2,再根据计算好的x2,y2计算x1，y1。
    //推理2，递推关系x1=y2,y1=x2-(a/b)*y2;
    long long t = y;
    y = x - (a/b) * y;//(a/b)向下取整
    x = t;
//    printf("x1=%d,y1=%d,r=%d\n",x,y,r);
    return r;
}
int main()
{
	long long a,b,c,k;//题意为a+cx=b%mod,x为可能解
	while(cin>>a>>b>>c>>k&&(a||b||c||k)){
		long long mod=llpow(2,k),x,y;//转化为cx+mody=b-a,裴蜀等式求解
		long long r=exgcd(mod,c,y,x);
		if((b-a)%r)
			cout<<"FOREVER"<<endl;
		else
			cout<<((b-a)/r*x%(mod/r)+mod/r)%(mod/r)<<endl;
	}
	return 0;
}
