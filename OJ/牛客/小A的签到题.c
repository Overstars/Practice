/*���ӣ�https://ac.nowcoder.com/acm/contest/549/A
��Դ��ţ����

ʱ�����ƣ�C/C++ 1�룬��������2��
�ռ����ƣ�C/C++ 262144K����������524288K
64bit IO Format: %lld
��Ŀ���� 
����һ��ǩ���⣬��Ҫ�������ʱ�����١�
��������һ�κܼ򵥵Ĵ��룬�������ύ���Ϳ���AC��
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

��������:
һ��һ������N
�������:
һ��һ��������ʾ���
ʾ��1
����
3
���
1
��ע:
3��N��1e11
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
