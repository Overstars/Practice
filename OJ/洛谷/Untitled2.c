#include<stdio.h>
int main()
{
	int a=6;
	printf("%d\n",a);
//	++a=5;
//	++5;
//	(++a)++;
	printf("%p\n",&(++a));
	return 0;
}
