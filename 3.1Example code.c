/*platium.c--your weight in platinum*/
#include<stdio.h>
int main(void)
{
	float weight;  /*your weight*/
	float value;  /*相等重量的白金价值*/
	
	printf("Are you worth your weight in platinum?\n");
	printf("Let's check it out.\n") ;
	printf("Please enter your weight in pounds:");
	
	/*Acquire users's input*/
	scanf("%f",&weight);
	/*Assume the price of platinum is 1700$/ounce*/
	/*14.5833 is used to change avoirdupois ounce into troy ounce*/
	value =1700.0*weight*14.5833;
	printf("Your weight in platinum is worth $%.2f.\n",value);
	printf("You easily worth thet!If platinum prices drop,\n");
	printf("eat more to maintain your value.\n");
	
	getchar();
	getchar();
	 
	return 0;
}
