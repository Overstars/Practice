#include<iostream>//推荐这篇https://blog.csdn.net/yoer77/article/details/69568676
#include<cstdio>//https://blog.csdn.net/baidu_33153085/article/details/52137179#commentBox
#include<algorithm>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y)
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
//通解x = x0 + b/gcd(a,b)*t;//x0为一特解
//y = y0 - a/gcd(a,b)*t;
//(x0, y0 为方程的一组特解， t为整数)
int main()
{
	long long x,y,m,n,l;//只能向西跳
	while(cin>>x>>y>>m>>n>>l){
		if(m>n)
			swap(m,n),swap(x,y);
		long long r,s,t;//设s步,t圈,则有(n-m)s+lt=x-y
		r=exgcd(l,n-m,t,s);//s是可能答案
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
		}//最小正整数解结论证明:https://www.cnblogs.com/hadilo/p/5914302.html第四部分
	}
	return 0;
}
