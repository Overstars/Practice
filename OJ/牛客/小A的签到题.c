/*链接：https://ac.nowcoder.com/acm/contest/549/A
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 262144K，其他语言524288K
64bit IO Format: %lld
题目描述 
这是一道签到题，主要考验比赛时的手速。
接下来是一段很简单的代码，或许你提交它就可以AC。
#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    scanf("%lld",&n);
    long long f1=1,f2=1,f3;
    for(int i=3;i<=n;i++) {
        f3=f1+f2;
        f1=f2;
        f2=f3;
    }
    printf("%lld\n",f3*f3-f1*f1-f1*f3);
    return 0;
}

输入描述:
一行一个整数N
输出描述:
一行一个整数表示结果
示例1
输入
3
输出
1
备注:
3≤N≤1e11
*/
#include<stdio.h>
#include<malloc.h>
//long long fibo[100000000005]={0};
int main(void)
{
    long long *fibo=(long long*)malloc(1000000005*sizeof(long long));
    long long i,n;
    fibo[1]=fibo[2]=1;
    for(i=3;i<=1000000000;i++)
        fibo[i]=fibo[i-2]+fibo[i-1];
    while(scanf("%lld",&n)==1){
        printf("%lld",fibo[n-1]*fibo[n-1]-fibo[n-2]*fibo[n-2]);
    }
    free(fibo);
    return 0;
}
