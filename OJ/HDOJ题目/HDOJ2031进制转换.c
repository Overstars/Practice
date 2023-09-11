#include<stdio.h>
void trans(long long n,int r);
char a[17]="0123456789ABCDEF";
int main(void)
{
    long long num;
    int r;

    while(scanf("%lld %d",&num,&r)==2){
        if(num<0){
            num=-num;
            putchar('-');
        }
        trans(num,r);
        putchar('\n');
    }
    return 0;
}
void trans(long long n,int r)
{
    if(n==0)
        return;
    if(0<n&&n<=r){
        putchar(a[n]);
        return;
    }
    else{
        trans(n/r,r);
        putchar(a[n%r]);
    }
}
