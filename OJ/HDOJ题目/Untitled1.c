#include<stdio.h>
int fun(int m, int n);
int main()
{
int fun(int m, int n);
   int m, n;
   scanf("%d %d",&m,&n);
   printf("%d",fun(m,n));
   return 0;
}
int fun(int m, int n)
{
  int i,j;
  int count=0;
  int temp=m;
  while(temp>0)
  {
  	if(temp%10==n)
  	count+=1;
  	temp=m/10;
  }
  return count;
}
