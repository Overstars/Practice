#include<stdio.h>
int main(void)
{
	char A;
	printf("Please input one character.\n");
	scanf("%c",&A);
	printf("So the ASCII code \"%d\" presents \"%c\".\n\n",A,A);
	
	int B;
	printf("Please input a piece ASCII code.\n");
	printf("___\b\b\b");
	scanf("%d",&B);
	printf("So the ASCII code \"%d\" presents \"\%c\".\n",B,B);
	
	system("pause");
	return 0;
}
