#include<stdio.h>

int main ()
{ 
    int x;
    scanf("%d",&x);
    if(99>x)
    printf("��������λ��");
    else if(x>999)
    printf("��������λ��"); 
    else
    {
        int a,b,c;
        a=x/100;
        b=x/10;
        b=b%10;
        c=x%10;
        x=c*100+b*10+a;
        printf("%d",x);
    }
    return 0;
}

