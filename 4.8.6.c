#include<stdio.h>
#include<string.h>
int main(void)
{
	char fname[20];
	char lname[20];
	
	printf("Please enter your firstname.\n");
	scanf("%s",fname);
	printf("Please enter your lastname.\n");
	scanf("%s",lname);
	
	printf("%s %s\n",fname,lname);
	printf("%*u %*u\n",strlen(fname),strlen(fname),strlen(lname),strlen(lname));
	printf("%-*u %-*u\n",strlen(fname),strlen(fname),strlen(lname),strlen(lname));
	
	return 0;
 } 
