#include<stdio.h>
#include<string.h>
int main(void)
{
	char lname[20];
	char fname[20];
	int lname_length,fname_length;
	
	printf("Please enter your lastname.\n");
	scanf("%s",lname);
	printf("Please enter your firstname\n");
	scanf("%s",fname);
	
	printf("a.\"%s,%s\"\n",lname,fname);
	printf("b.\"%20s,%20s\"\n",lname,fname);
	printf("c.\"%-20s,%-20s\"\n",lname,fname);
	printf("d.\"%*s,%*s\"\n",strlen(lname)+3,lname,strlen(fname)+3,fname);
	
	return 0;
}
