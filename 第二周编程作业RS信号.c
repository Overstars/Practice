#include<stdio.h>
int main(void)
{
	int RS,R,S;
	scanf("%d",&RS);
	R=RS/10;
	S=RS%10;
	switch(S)
	{
		case 1:
			printf("Faint signals, barely perceptible,");
			break;
		case 2:
			printf("Very weak signals,");
			break;
		case 3:
			printf("Weak signals,");
			break;
		case 4:
			printf("Fair signals,");
			break;
		case 5:
			printf("Fairly good signals,");
			break;
		case 6:
			printf("Good signals,");
			break;
		case 7:
			printf("Moderately strong signals,");
			break;
		case 8:
			printf("Strong signals,");
			break;
		case 9:
			printf("Extremely strong signals,");
			break;
	}
	switch(R)
	{
		case 1:
			printf("Unreadable\n");
			break;
		case 2:
			printf("Barely readable, occasional words distinguishable\n");
			break;
		case 3:
			printf("Readable with considerable difficulty\n");
			break;
		case 4:
			printf("Readable with practically no difficulty\n");
			break;
		case 5:
			printf("Perfectly readable\n");
			break;
	}
	
	return 0;
 } 
